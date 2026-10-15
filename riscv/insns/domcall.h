#include "jitdomain.h"

require_extension(EXT_XJITDOMAIN);
CHECK_RD();
const reg_t dom = DOMINSN_DOM(insn.bits());
if (!((STATE.dgate->read() >> (8 * STATE.curdom + dom)) & 1))
  DOMAIN_CFI_FAULT(DCAUSE_GATE);
reg_t link = npc;
set_pc(RS1 & ~reg_t(1));
reg_t drs_sp = DRS_SP() - 16;
DRS_ACCESS(MMU.store<uint64_t>(drs_sp, link, {.dom_drs=true}),
           MMU.store<uint64_t>(drs_sp + 8, STATE.curdom, {.dom_drs=true}));
STATE.dsp->write(drs_sp);
WRITE_RD(link);
p->set_dom_state(STATE.curdom, {true, dom, DOMINSN_LABEL(insn.bits())});
serialize();
