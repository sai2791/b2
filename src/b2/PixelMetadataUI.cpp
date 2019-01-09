#include <shared/system.h>
#include "PixelMetadataUI.h"

#if VIDEO_TRACK_METADATA

#include "SettingsUI.h"
#include "BeebWindow.h"
#include "dear_imgui.h"
#include <beeb/video.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class PixelMetadataUI:
    public SettingsUI
{
public:
    explicit PixelMetadataUI(BeebWindow *beeb_window);

    void DoImGui(CommandContextStack *cc_stack) override;

    bool OnClose() override;
protected:
private:
    BeebWindow *m_beeb_window=nullptr;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

PixelMetadataUI::PixelMetadataUI(BeebWindow *beeb_window):
    m_beeb_window(beeb_window)
{
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void PixelMetadataUI::DoImGui(CommandContextStack *cc_stack) {
    (void)cc_stack;

    if(const VideoDataUnitMetadata *m=m_beeb_window->GetMetadataForMousePixel()) {
        if(m->flags&VideoDataUnitMetadataFlag_HasAddress) {
            ImGui::Text("Address: $%04X",m->address);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

bool PixelMetadataUI::OnClose() {
    return false;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::unique_ptr<SettingsUI> CreatePixelMetadataUI(BeebWindow *beeb_window) {
    return std::make_unique<PixelMetadataUI>(beeb_window);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
