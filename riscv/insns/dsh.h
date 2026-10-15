require_extension(EXT_XJITDOMAIN);
MMU.store<uint16_t>(RS1 + insn.s_imm(), RS2, {.dom_typed=true});
