#include <YSI_Coding\y_hooks>


new bool:Inauguracao[MAX_PLAYERS];
new bool:PlayIna[MAX_PLAYERS];
new bool:TemInauguracao;
new TempoRestante;
new TimerInau;
new TelaInau;

hook OnPlayerConnect(playerid)
{
    if(TemInauguracao == false) return 1;
    if(TempoRestante > 0)
    {
        MostrarInau(playerid);
        SetTimerEx("Inabug", 2000, false, "d", playerid);
    }
    else if(TempoRestante == -1)
    {
        TogglePlayerSpectating(playerid, 1);
        if(TempoRestante <= 57){
            PlayIna[playerid] = true;
            PlayAudioStreamForPlayer(playerid, "https://www.dl.dropboxusercontent.com/s/7l73rsmm2zc3466/rippzy.mp3?dl=1");
        }
    }
    Inauguracao[playerid] = true;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Inauguracao[playerid] = false;
    PlayIna[playerid] = false;
    return 1;
}

function Inabug(playerid)
{
    TogglePlayerSpectating(playerid, 1);
    InterpolateCameraPos(playerid, 1347.944824, -984.886657, 32.058792, 1347.944824, -984.886657, 32.058792, 1);
    InterpolateCameraLookAt(playerid, 1343.169921, -984.904296, 33.542175, 1343.169921, -984.904296, 33.542175, 1);
    return 1;
}

function TelaInauu()
{
    new TelaLL[25];
    if(TempoRestante > 0)
    {
        TempoRestante--;
        format(TelaLL, sizeof(TelaLL), "%s", SegundosParaMinutosEx(TempoRestante));
    }

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == true) continue;
        if(Inauguracao[i] == false) continue;
        
        if(TempoRestante <= 57 && PlayIna[i] == false){
            PlayIna[i] = true;
            PlayAudioStreamForPlayer(i, "https://www.dropbox.com/s/7l73rsmm2zc3466/rippzy.mp3?dl=1");
        }

        if(TempoRestante >= 0) PlayerTextDrawSetString(i, InauT[i][4], TelaLL);
        else if(TempoRestante == -1)
        {
            switch(TelaInau)
            {
                case 0:
                {
                    OcultarInau(i);
                    InterpolateCameraPos(i, 125.217872, 2110.406982, 85.150436, 129.056213, 2438.763427, 17.186697, 9000);
                    InterpolateCameraLookAt(i, 125.641456, 2105.714111, 83.477951, 129.459182, 2443.744628, 17.345613, 9000);
                }
                case 1:
                {
                    InterpolateCameraPos(i, 1135.011962, 1826.039794, 14.658808, 1131.245605, 1909.535278, 65.929405, 9000);
                    InterpolateCameraLookAt(i, 1135.199584, 1821.305664, 16.256610, 1128.311645, 1910.598632, 62.022880, 9000);
                }
                case 2:
                {
                    InterpolateCameraPos(i, 2115.027832, 2130.828125, 11.556204, 2160.100097, 2167.109130, 63.217655, 9000);
                    InterpolateCameraLookAt(i, 2117.555175, 2126.517089, 11.390428, 2163.881347, 2164.243652, 61.639343, 9000);   
                }
                case 3:
                {
                    InterpolateCameraPos(i, 2672.084228, 897.494262, 18.772605, 2758.576904, 968.683715, 24.385961, 9000);
                    InterpolateCameraLookAt(i, 2674.119140, 901.312622, 21.278354, 2762.263916, 965.414367, 23.538682, 9000);
                }
                case 4:
                {
                    InterpolateCameraPos(i, 1342.681640, -1245.122314, 13.196335, 1345.384033, -1430.260009, 16.874588, 9000);
                    InterpolateCameraLookAt(i, 1342.674682, -1250.120605, 13.066627, 1347.554199, -1434.715576, 17.536745, 9000);
                }
                case 5:
                {
                    InterpolateCameraPos(i, 1540.902465, -1666.566772, 37.332649, 1533.030273, -1617.844726, 14.312824, 9000);
                    InterpolateCameraLookAt(i, 1544.726562, -1667.921875, 40.254997, 1537.628540, -1619.766601, 13.910260, 9000);
                }
                case 6:
                {
                    InterpolateCameraPos(i, 1542.966674, -1685.105468, 14.726365, 1465.886474, -1684.287963, 51.235240, 9000);
                    InterpolateCameraLookAt(i, 1544.475341, -1689.872314, 14.692864, 1467.646484, -1688.590454, 49.393859, 9000);  
                }
                case 7:
                {
                    InterpolateCameraPos(i, 1380.569946, -1732.619262, 17.328689, 1558.922973, -1713.205932, 116.027755, 9000);
                    InterpolateCameraLookAt(i, 1375.750976, -1733.007324, 18.603992, 1555.391723, -1715.510986, 113.341423, 9000);
                }
                case 8:
                {
                    InterpolateCameraPos(i, 1706.215698, -1957.116455, 13.305109, 2155.087158, -1958.417358, 15.273532, 9000);
                    InterpolateCameraLookAt(i, 1710.671142, -1955.306152, 14.673210, 2150.610839, -1956.195190, 15.119779, 9000);
                }
                case 9:
                {
                    InterpolateCameraPos(i, -379.535675, -1548.219970, 25.072881, -502.309875, -1507.764038, 107.302276, 9000);
                    InterpolateCameraLookAt(i, -379.278015, -1543.255615, 24.535257, -498.781127, -1507.938720, 103.764266, 9000);
                }
                case 10:
                {
                    InterpolateCameraPos(i, -1113.141113, -1637.055175, 92.377426, -1042.482421, -1601.985473, 81.263542, 9000);
                    InterpolateCameraLookAt(i, -1117.890136, -1635.931396, 93.465751, -1046.929931, -1604.231567, 80.845642, 9000);
                }
                case 11:
                {
                    InterpolateCameraPos(i, 1395.508300, -981.388122, 57.511959, 1342.636108, -984.645812, 37.290969, 9000);
                    InterpolateCameraLookAt(i, 1400.491699, -980.980957, 57.490482, 1337.686035, -984.668029, 36.586269, 9000);   
                }
                case 12:
                {
                    Inauguracao[i] = false;
                    MostrarLogin(i);
                }
            }
        }
    }

    if(TelaInau == 12)
    {
        TemInauguracao = false;
        TempoRestante = -2;
    }

    if(TempoRestante == -1) TelaInau++;
    else if(TempoRestante == -2) KillTimer(TimerInau);
    else if(TempoRestante == 0)
    {
        KillTimer(TimerInau);
        TimerInau = SetTimer("TelaInauu", 10000, true);
        TempoRestante = -1;
        return TelaInauu();
    }
    return 1;
}

CMD:ina(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(TemInauguracao == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Inauguração já iniciada.");
    new tempoo;
    if(sscanf(params, "d", tempoo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Ina [Minutos]");
    TempoRestante = (tempoo*60);
    TelaInau = 0;
    TemInauguracao = true;
    TimerInau = SetTimer("TelaInauu", 1000, true);
    SendClientMessage(playerid, -1, "| ADMIN | Você iniciou.");
    return 1;
}

CMD:rpnull(playerid)
{
    if(Inauguracao[playerid] == false) return 0;
    Inauguracao[playerid] = false;
    if(TempoRestante > 0) OcultarInau(playerid);
    MostrarLogin(playerid);
    return 1;
}