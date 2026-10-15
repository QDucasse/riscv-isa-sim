require_extension(EXT_XJITDOMAIN);
WRITE_RD(MMU.load<uint32_t>(RS1 + insn.i_imm(), {.dom_typed=true}));
