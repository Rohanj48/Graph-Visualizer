#include "lib/raywin.h"
#include "lib/raywin.h"
#include "lib/graph.h"
#include "lib/alg.h"
int main()
{

    Raywin Game;
    Graph G1;

    while (Game.windowShouldNotClose())
    {

        // to be called in order
        Game.windowDrawCalls();
        // window draw calles here

        G1.createNodeOverlay(Game.main_camera);

        Game.CameraDrawCalls();
        // draw graps herer

        G1.drawStructure(Game.main_camera);
        Game.windowCameraEndDrawCalls();
        // anythig draw above wiill come under the camera
    }
    return 0;
}