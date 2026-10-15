#include "jitdomain.h"

require_extension(EXT_XJITDOMAIN);
reg_t drs_sp = DRS_SP();
reg_t ret_pc = 0, ret_dom = 0;
DRS_ACCESS(ret_pc = MMU.load<uint64_t>(drs_sp, {.dom_drs=true}),
           ret_dom = MMU.load<uint8_t>(drs_sp + 8, {.dom_drs=true}));
if (ret_dom >= JITDOMAIN_NDOMS)
  DOMAIN_CFI_FAULT(DCAUSE_DRS);
set_pc(ret_pc);
STATE.dsp->write(drs_sp + 16);
p->set_dom_state(ret_dom, STATE.dpend);
serialize();
