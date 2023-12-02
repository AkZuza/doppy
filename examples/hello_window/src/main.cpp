#include <doppy.h>

class TestWindow : public ClientWindow
{
public:

	using ClientWindow::ClientWindow;

	void OnUserCreate() override
	{}

	void OnUserUpdate() override
	{}

	void OnUserDestroy() override
	{}
};

int main()
{
	TestWindow window("Hello Window", 1280, 720);
	window.Run();
}