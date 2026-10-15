require_extension(EXT_XJITDOMAIN);
WRITE_RD(MMU.load<int64_t>(RS1 + insn.i_imm(), {.dom_typed=true}));
