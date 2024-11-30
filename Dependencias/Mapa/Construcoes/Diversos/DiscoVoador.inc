#include <YSI_Coding\y_hooks>

new bool:Apareceu;
new TeporizadorDisc;

hook OnGameModeInit()
{
    TeporizadorDisc = SetTimer("IniciarDisco", 2000, true);
    return 1;
}

function IniciarDisco()
{
    if(Apareceu == false)
    {
        new horaX, minutosX, segundosX;
        gettime(horaX, minutosX, segundosX);
        if(horaX >= 18 && horaX <= 23)
        {
            CreateDynamicObject(18656, 1488.49890, -1393.98987, 378.45090,   -90.00000, 1.83500, 356.93451, -1, 0, -1, 780.0, 780.0);
            CreateDynamicObject(18846, 1488.62976, -1393.24805, 377.20999,   0.00000, 0.00000, 0.00000, -1, 0, -1, 780.0, 780.0);
            SendClientMessageToAll(0x7CFC00FF, "| NEWS | Um OVNI foi avistado na região de Los Santos");
            Apareceu = true;
            KillTimer(TeporizadorDisc);
        }
    }
    return 1;
}