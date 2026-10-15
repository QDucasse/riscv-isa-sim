require_extension(EXT_XJITDOMAIN);
// The match against dpend was checked before execution (check_if_domlpad_required)
if (STATE.dpend.valid) {
  p->set_dom_state(STATE.dpend.dom, {});
  serialize();
}
