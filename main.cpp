#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "olcPGEX_LayerController.h"

// Override base class with your custom functionality
class LC_Example : public olc::PixelGameEngine
{
public:
	LC_Example()
	{
		// Name your application
		sAppName = "LayerController";
	}
    std::string ui_layer = "1";
    std::string first_layer = "2";
    std::string second_layer = "3";
    std::string main_layer = "4a 65 73 75 73 4c 6f 76 65 73 59 6f 75";

public:
	bool OnUserCreate() override
	{
        // Layers should be created in order from top to bottom 
        // (i.e., ui first then main then background)
		olc::LayerController::CreateLayer(ui_layer);
		olc::LayerController::CreateLayer(first_layer);
		olc::LayerController::CreateLayer(main_layer);
		olc::LayerController::CreateLayer(second_layer);
        
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
        olc::LayerController::SetActiveLayer(main_layer);

        olc::vf2d vMouse = GetMousePos();

        Clear(olc::VERY_DARK_BLUE);

        olc::LayerController::SetActiveLayer(ui_layer);
        Clear(olc::BLANK);

        DrawString({16,16}, std::to_string(GetFPS()), olc::YELLOW);

        olc::LayerController::SetActiveLayer(main_layer);
        Clear(olc::BLANK);

        FillCircle(vMouse, 8, olc::WHITE);

        olc::LayerController::SetActiveLayer(first_layer);
        Clear(olc::BLANK);

        FillRect({64, 0}, {128,256}, olc::VERY_DARK_GREEN);

        olc::LayerController::SetActiveLayer(second_layer);
        Clear(olc::BLANK);

        FillRect({0,0},{256,256}, olc::VERY_DARK_BLUE);

		return true;
	}
};

int main(int argc, char const *argv[])
{
    LC_Example demo;
    
    if (demo.Construct(256,256,2,2))
        demo.Start();

    return 0;
}
