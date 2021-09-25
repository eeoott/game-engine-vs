#include <windows.h>
#include <windowsx.h>
#include "BaseApplication.hpp"
namespace GEVS {
    class WindowApplication : public BaseApplication {
        public:
            WindowApplication(GfxConfiguration& config): BaseApplication(config)
            {
            };

            virtual int Initialize();
            virtual void Finalize();
            virtual void Tick();

            // the WindowProc function prototype
            static LRESULT CALLBACK WindowProc(HWND hWnd,
                                               UINT message,
                                               WPARAM wParam,
                                               LPARAM lParam);
    };
}


