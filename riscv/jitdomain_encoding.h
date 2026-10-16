// See LICENSE for license details.
// JITDomain (custom extension Xjitdomain) encodings. Included at the end of
// encoding.h so that the DECLARE_CSR and DECLARE_CAUSE tables pick these up.

#ifndef RISCV_JITDOMAIN_ENCODING_H
#define RISCV_JITDOMAIN_ENCODING_H

#define CSR_DSTATUS 0x5c0
#define CSR_DRIGHTS0 0x5c1
#define CSR_DRIGHTS1 0x5c2
#define CSR_DRIGHTS2 0x5c3
#define CSR_DTARGET 0x5c4
#define CSR_DGATE 0x5c5
#define CSR_DSP 0x5c6
#define CSR_DCAUSE 0xdc0
#define CSR_DMPCFG0 0x7c3
#define CSR_DMPCFG1 0x7c4
#define CSR_MDSTATUS 0x7c5
#define CSR_CURDOM 0xcc0

#define DSTATUS_EN 0x00000001
#define DSTATUS_SPD 0x0000000e
#define DSTATUS_SPPEND 0x0001fff0
#define DSTATUS_DRSKEY 0x000e0000
#define DSTATUS_SCHK 0x00100000

#define MDSTATUS_MPD 0x0000000e
#define MDSTATUS_MPPEND 0x0001fff0

// Packed dpend, as held in xPPEND and in curdom[15:3]
#define DPEND_DOM 0x0007
#define DPEND_LABEL 0x0ff8
#define DPEND_VALID 0x1000

#define CURDOM_DOM 0x0007
#define CURDOM_PEND 0xfff8

// Key in leaf PTE bits [56:54], reserved again when dstatus.EN = 0
#define PTE_DOMKEY 0x01C0000000000000ULL

// drights entry {X, W, R}
#define DRIGHT_R 0x1
#define DRIGHT_W 0x2
#define DRIGHT_X 0x4

#define DMPCFG_K 0x7
#define DMPCFG_L 0x8

#define DCAUSE_LPAD 1
#define DCAUSE_DRS 2
#define DCAUSE_GATE 3

// domcall/domlpad immediate: dom in imm[11:9], label in imm[8:0]
#define DOMINSN_DOM(bits) (((bits) >> 29) & 0x7)
#define DOMINSN_LABEL(bits) (((bits) >> 20) & 0x1ff)

#define MATCH_DLB 0xb
#define MASK_DLB 0x707f
#define MATCH_DLH 0x100b
#define MASK_DLH 0x707f
#define MATCH_DLW 0x200b
#define MASK_DLW 0x707f
#define MATCH_DLD 0x300b
#define MASK_DLD 0x707f
#define MATCH_DLBU 0x400b
#define MASK_DLBU 0x707f
#define MATCH_DLHU 0x500b
#define MASK_DLHU 0x707f
#define MATCH_DLWU 0x600b
#define MASK_DLWU 0x707f
#define MATCH_DSB 0x2b
#define MASK_DSB 0x707f
#define MATCH_DSH 0x102b
#define MASK_DSH 0x707f
#define MATCH_DSW 0x202b
#define MASK_DSW 0x707f
#define MATCH_DSD 0x302b
#define MASK_DSD 0x707f
#define MATCH_DOMCALL 0x5b
#define MASK_DOMCALL 0x707f
#define MATCH_DOMRET 0x105b
#define MASK_DOMRET 0xffffffff
#define MATCH_DOMLPAD 0x205b
#define MASK_DOMLPAD 0xfffff

#define CAUSE_DOMAIN_ACCESS 0x18
#define CAUSE_DOMAIN_CFI 0x19

#endif
#ifdef DECLARE_INSN
DECLARE_INSN(dlb, MATCH_DLB, MASK_DLB)
DECLARE_INSN(dlh, MATCH_DLH, MASK_DLH)
DECLARE_INSN(dlw, MATCH_DLW, MASK_DLW)
DECLARE_INSN(dld, MATCH_DLD, MASK_DLD)
DECLARE_INSN(dlbu, MATCH_DLBU, MASK_DLBU)
DECLARE_INSN(dlhu, MATCH_DLHU, MASK_DLHU)
DECLARE_INSN(dlwu, MATCH_DLWU, MASK_DLWU)
DECLARE_INSN(dsb, MATCH_DSB, MASK_DSB)
DECLARE_INSN(dsh, MATCH_DSH, MASK_DSH)
DECLARE_INSN(dsw, MATCH_DSW, MASK_DSW)
DECLARE_INSN(dsd, MATCH_DSD, MASK_DSD)
DECLARE_INSN(domcall, MATCH_DOMCALL, MASK_DOMCALL)
DECLARE_INSN(domret, MATCH_DOMRET, MASK_DOMRET)
DECLARE_INSN(domlpad, MATCH_DOMLPAD, MASK_DOMLPAD)
#endif
#ifdef DECLARE_CSR
DECLARE_CSR(dstatus, CSR_DSTATUS)
DECLARE_CSR(drights0, CSR_DRIGHTS0)
DECLARE_CSR(drights1, CSR_DRIGHTS1)
DECLARE_CSR(drights2, CSR_DRIGHTS2)
DECLARE_CSR(dtarget, CSR_DTARGET)
DECLARE_CSR(dgate, CSR_DGATE)
DECLARE_CSR(dsp, CSR_DSP)
DECLARE_CSR(dcause, CSR_DCAUSE)
DECLARE_CSR(dmpcfg0, CSR_DMPCFG0)
DECLARE_CSR(dmpcfg1, CSR_DMPCFG1)
DECLARE_CSR(mdstatus, CSR_MDSTATUS)
DECLARE_CSR(curdom, CSR_CURDOM)
#endif
#ifdef DECLARE_CAUSE
DECLARE_CAUSE("domain access fault", CAUSE_DOMAIN_ACCESS)
DECLARE_CAUSE("domain cfi fault", CAUSE_DOMAIN_CFI)
#endif
