#ifndef HEADER_297BD1FD68834B09A1FBE55C2A4AAE8B // -*- mode:c++ -*-
#define HEADER_297BD1FD68834B09A1FBE55C2A4AAE8B

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#include <memory>

class SettingsUI;
class BeebWindow;
class ImGuiStuff;

std::unique_ptr<SettingsUI> CreateCommandKeymapsUI(BeebWindow *beeb_window, ImGuiStuff *imgui_stuff);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
