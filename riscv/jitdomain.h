// See LICENSE for license details.

#ifndef _RISCV_JITDOMAIN_H
#define _RISCV_JITDOMAIN_H

#define DOMAIN_CFI_FAULT(subcode) ({ \
    STATE.dcause->write(subcode); \
    throw trap_domain_cfi(pc); \
  })

// Implicit DRS accesses: an access fault becomes a domain CFI fault (DRS)
#define DRS_ACCESS(...) do { \
    try { __VA_ARGS__; } \
    catch (trap_load_access_fault&) { DOMAIN_CFI_FAULT(DCAUSE_DRS); } \
    catch (trap_store_access_fault&) { DOMAIN_CFI_FAULT(DCAUSE_DRS); } \
    catch (trap_domain_access_fault&) { DOMAIN_CFI_FAULT(DCAUSE_DRS); } \
  } while (0)

// DRS records are 16 bytes, {pc (8 B), dom (1 B), pad (7 B)}, growing downward
#define DRS_SP() ({ \
    reg_t drs_sp = STATE.dsp->read(); \
    if (drs_sp % 16 != 0) \
      DOMAIN_CFI_FAULT(DCAUSE_DRS); \
    drs_sp; \
  })

#endif
