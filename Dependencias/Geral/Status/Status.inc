#include <YSI_Coding\y_hooks>

enum StatusJogador
{
    TempoStatus,
    TempoVacina,
    bool:StatusIniciado
};

new pStatus[MAX_PLAYERS][StatusJogador];

hook OnPlayerConnect(playerid)
{
    if(pStatus[playerid][StatusIniciado] == false)
    {
        pStatus[playerid][TempoStatus] = SetTimerEx("ProgressoStatus", 2000, true, "d", playerid); 
        pStatus[playerid][TempoVacina] = SetTimerEx("TempoVacinaAH", 1000, true, "d", playerid); 
        pStatus[playerid][StatusIniciado] = true;
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "StatusProgre") == 0)
    {
        MostrarStatus(playerid);
        AtualizarStatus(playerid);
        SetPVarInt(playerid, "StatusProgre", 1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "ASDKASLKDLASDLA") == 1) KillTimer(GetPVarInt(playerid, "SonoID"));

    if(pStatus[playerid][StatusIniciado] == true)
    {
        KillTimer(pStatus[playerid][TempoStatus]);
        KillTimer(pStatus[playerid][TempoVacina]);
    }
    new Deletar[StatusJogador];
    pStatus[playerid] = Deletar;
    return 1;
}

function TempoVacinaAH(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "ProgressoVacina", 1)) return 1;
    if(Jogador[playerid][Vacina] < 1) return 1;
    Jogador[playerid][Vacina]--;
    if(Jogador[playerid][Vacina] < 1) Jogador[playerid][Vacina] = 0;
    return 1;
}

function ProgressoStatus(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "ProgressoStatus", 1)) return 1;
    if(Jogador[playerid][Admin] > 0) return 1;
    if(GetPVarInt(playerid, "EventoJogador") > 0) return 1;
    if(Jogador[playerid][Preso] > 0) return 1;

    if(GetPVarInt(playerid, "FomeUpdate") < gettime()){
        if(GetPVarInt(playerid, "FomeUpdate") != 0){
            if(random(100) < 40)
            {
                if(Jogador[playerid][Fome] > 0)
                {
                    Jogador[playerid][Fome] -= 1.0;
                    if(Jogador[playerid][Fome] < 7.0) SendClientMessage(playerid, 0xF5DEB3FF, "| FOME | Você está com fome, vá até uma lanchonete ou restaurante.");
                }
                else
                {
                    EnviarHospital(playerid);
                    Jogador[playerid][Fome] = 15.0; 
                    Jogador[playerid][Dinheiro] -= 1500;
                    SendClientMessage(playerid, 0xADD8E6FF, "| MORTE | Você desmaiou de fome e foi parar no hospital. Custo: R$1.500");
                } 
            }
        }
        SetPVarInt(playerid, "FomeUpdate", gettime()+60);
    }

    if(GetPVarInt(playerid, "SedeUpdate") < gettime()){
        if(GetPVarInt(playerid, "SedeUpdate") != 0){
            if(random(100) < 50)
            {
                if(Jogador[playerid][Sede] > 0)
                {
                    Jogador[playerid][Sede] -= 1.0;
                    if(Jogador[playerid][Sede] < 7.0) SendClientMessage(playerid, 0xF5DEB3FF, "| SEDE | Você está com sede, vá até uma lanchonete ou restaurante.");
                }
                else
                {
                    EnviarHospital(playerid);
                    Jogador[playerid][Sede] = 15.0;
                    Jogador[playerid][Dinheiro] -= 1500;
                    SendClientMessage(playerid, 0xADD8E6FF, "| MORTE | Você desmaiou de sede e foi parar no hospital. Custo: R$1.500");
                }
            }
        }
        SetPVarInt(playerid, "SedeUpdate", gettime()+60);
    }

    if(GetPVarInt(playerid, "SaudeUpdate") < gettime()){
        if(GetPVarInt(playerid, "SaudeUpdate") != 0){
            if(Jogador[playerid][Doenca] > 0){
                if(random(100) < 70)
                {
                    if(Jogador[playerid][Saude] > 0)
                    {
                        Jogador[playerid][Saude] -= 1.0;
                        if(Jogador[playerid][Sede] < 7.0) SendClientMessage(playerid, 0xF5DEB3FF, "| SAÚDE | Você está doente, vá até o hospital para curar da sua doença.");
                    }
                    else
                    {
                        EnviarHospital(playerid);
                        Jogador[playerid][Saude] = 100.0;
                        Jogador[playerid][Doenca] = 0;
                        Jogador[playerid][Dinheiro] -= 2900;
                        SendClientMessage(playerid, 0xADD8E6FF, "| MORTE | Você morreu por conta de uma doença. Custo: R$2.900");
                    }
                }
            }
        }
        SetPVarInt(playerid, "SaudeUpdate", gettime()+60);
    }

    if(GetPVarInt(playerid, "SonoUpdate") < gettime()){
        if(GetPVarInt(playerid, "SonoUpdate") != 0){
            if(random(100) < 30){
                if(Jogador[playerid][Sono] > 0)
                {
                    Jogador[playerid][Sono] -= 1.0;
                    if(Jogador[playerid][Sono] < 7.0) SendClientMessage(playerid, 0xF5DEB3FF, "| SONO | Procure um hotel ou vá para sua casa dormir.");
                }
                else
                {
                    Jogador[playerid][Sono] = 50.0;
                    TogglePlayerControllable(playerid, 0);
                    ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
                    SendClientMessage(playerid, 0xF5DEB3FF, "| SONO | Você apagou no chão de sono, aguarde.");
                    EnviarSono(playerid);
                }
            }
        }
        SetPVarInt(playerid, "SonoUpdate", gettime()+60);
    }

    if(Jogador[playerid][VicioEstilo] > 0){
        if(GetPVarInt(playerid, "VicioUpdate") < gettime()){
            if(GetPVarInt(playerid, "VicioUpdate") != 0){
                if(random(100) < 20){
                    if(Jogador[playerid][Vicio] > 0)
                    {
                        Jogador[playerid][Vicio] -= 1.0;
                        if(Jogador[playerid][Vicio] < 7.0) SendClientMessage(playerid, 0xF5DEB3FF, "| VÍCIO | Você está ficando louco(a), use suas drogas.");
                    }
                    else
                    {
                        Jogador[playerid][Vicio] = 30.0;
                        SetPlayerDrunkLevel(playerid, 5000);
                    }
                }
            }
            SetPVarInt(playerid, "VicioUpdate", gettime()+60);
        }
    }

    AtualizarStatus(playerid);
    return 1;
}

stock AtualizarStatus(playerid)
{
    if(Jogador[playerid][SemStatus] == true) return 1;
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][15], (595.0 + ((35.0 * Jogador[playerid][Fome]) / 100)), 0.000000);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][16], (595.0 + ((35.0 * Jogador[playerid][Sede]) / 100)), 0.000000); 
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][17], (595.0 + ((35.0 * Jogador[playerid][Saude]) / 100)), 0.000000); 
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][18], (595.0 + ((35.0 * Jogador[playerid][Sono]) / 100)), 0.000000);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][19], (595.0 + ((35.0 * Jogador[playerid][Vicio]) / 100)), 0.000000);
    PlayerTextDrawShow(playerid, StatusTxd[playerid][15]);
    PlayerTextDrawShow(playerid, StatusTxd[playerid][16]);
    PlayerTextDrawShow(playerid, StatusTxd[playerid][17]);
    PlayerTextDrawShow(playerid, StatusTxd[playerid][18]);
    PlayerTextDrawShow(playerid, StatusTxd[playerid][19]);
    return 1;
}

stock EnviarHospital(playerid)
{
    cAC[playerid][MorreuStatus] = true;
    SetPlayerHealth(playerid, 0.0);
    SetTimerEx("VerificarMorte", 1000, false, "d", playerid);
    return 1; 
}

stock EnviarSono(playerid)
{
    if(GetPVarInt(playerid, "ASDKASLKDLASDLA") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está dormindo");
    SetPVarInt(playerid, "ASDKASLKDLASDLA", 1);
    new ii = SetTimerEx("Acordar", 1000*(random(60+30)+30), false, "d", playerid);
    SetPVarInt(playerid, "SonoID", ii);
    TogglePlayerControllable(playerid, 0);
    MostrarTelaSono(playerid);
    return 1;
}

function Acordar(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);
    Jogador[playerid][Sono] = 100.0;
    SetPVarInt(playerid, "ASDKASLKDLASDLA", 0);
    OcultarTelaSono(playerid);
    CallRemoteFunction("OnPlayerAcordou", "d", playerid);
    AtualizarStatus(playerid);
    return 1;
}

CMD:live(playerid)
{
    if(Jogador[playerid][SemStatus] == false){
        OcultarStatusEx(playerid);
        OcultarRelogio(playerid);
        Jogador[playerid][SemStatus] = true;  
        SendClientMessage(playerid, 0x00BFFFFF, "| STATUS | Seu status foi ocultado");
        return 1;
    }

    MostrarRelogio(playerid);
    MostrarStatusEx(playerid);
    Jogador[playerid][SemStatus] = false;  
    SendClientMessage(playerid, 0x00BFFFFF, "| STATUS | Seu status foi ativo novamente");
    return 1;
}