Dialog:AmmunationMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de armas nessa empresa");

    switch(listitem)
    {
        // Taco de Golf
        case 0:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 600) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 2, 3500)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para arma branca");
            GivePlayerWeapon(playerid, 2, 1);
            Jogador[playerid][Dinheiro] -= 600;
            EnviarDinheiroEmpresa(id, 600);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou um Taco de Golf por $600");
        }

        // Taco
        case 1:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 750) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 5, 1)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para arma branca");
            GivePlayerWeapon(playerid, 5, 1);
            Jogador[playerid][Dinheiro] -= 750;
            EnviarDinheiroEmpresa(id, 750);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou um Taco por $750");
        }

        // Pá
        case 2:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 300) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 6, 1)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para arma branca");
            GivePlayerWeapon(playerid, 6, 1);
            Jogador[playerid][Dinheiro] -= 300;
            EnviarDinheiroEmpresa(id, 300);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou um Pá por $300");
        }

        // Granadas
        /*case 3:
        {
            if(Jogador[playerid][Dinheiro] < 1900) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArma(playerid, 16)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui granadas");
            GivePlayerWeapon(playerid, 16, 16);
            Jogador[playerid][Dinheiro] -= 1900;
            EnviarDinheiroEmpresa(id, 1900);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou granadas por $1.900");
        }*/

        // 9mm
        case 3:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 2500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 22, 3000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para pistola");
            GivePlayerWeapon(playerid, 22, 900);
            Jogador[playerid][Dinheiro] -= 2500;
            EnviarDinheiroEmpresa(id, 2500);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Pistola 9mm por $2.500");
        }

        // 9mm Silenciada
        case 4:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 3800) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 22, 2000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para pistola");
            GivePlayerWeapon(playerid, 23, 900);
            Jogador[playerid][Dinheiro] -= 3800;
            EnviarDinheiroEmpresa(id, 3800);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Pistola 9mm Silenciada por $3.800");
        }

        // Shotgun
        case 5:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 25, 2000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para doze");
            GivePlayerWeapon(playerid, 25, 800);
            Jogador[playerid][Dinheiro] -= 3000;
            EnviarDinheiroEmpresa(id, 3000);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Shotgun por $3.000");
        }

        // Combat Shotgun
        case 6:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 3500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 27, 3500)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para doze");
            GivePlayerWeapon(playerid, 27, 800);
            Jogador[playerid][Dinheiro] -= 3500;
            EnviarDinheiroEmpresa(id, 3500);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Combat Shotgun por $3.500");
        }

        // MP5
        case 7:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 29, 3500)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para arma");
            GivePlayerWeapon(playerid, 29, 4000);
            Jogador[playerid][Dinheiro] -= 2000;
            EnviarDinheiroEmpresa(id, 2000);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma MP5 por $2.000");
        }

        // Sniper
        case 8:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 34, 2000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para sniper");
            GivePlayerWeapon(playerid, 34, 1000);
            Jogador[playerid][Dinheiro] -= 3000;
            EnviarDinheiroEmpresa(id, 3000);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Sniper por $3.000");
        }

        // Rifle
        case 9:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 33, 2000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para rifle");
            GivePlayerWeapon(playerid, 33, 500);
            Jogador[playerid][Dinheiro] -= 2000;
            EnviarDinheiroEmpresa(id, 2000); 
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Rifle por $2.000");
        }

        // Desert
        case 10:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 24, 2500)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para desert");
            GivePlayerWeapon(playerid, 24, 500);
            Jogador[playerid][Dinheiro] -= 1500;
            EnviarDinheiroEmpresa(id, 1500); 
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Desert por $1.500");
        }

        // Sawnoff
        case 11:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 26, 2500)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para sawnoff");
            GivePlayerWeapon(playerid, 26, 600);
            Jogador[playerid][Dinheiro] -= 1500;
            EnviarDinheiroEmpresa(id, 1500); 
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma Sawnoff por $1.500");
        }

        // M4
        case 12:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
            if(Jogador[playerid][Dinheiro] < 3600) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArmaLimite(playerid, 31, 5000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui o máximo de balas para M4");
            GivePlayerWeapon(playerid, 31, 900);
            Jogador[playerid][Dinheiro] -= 3600;
            EnviarDinheiroEmpresa(id, 3600); 
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma M4 por $3.600");
        }

        // Dinamites
        case 13:
        {
            if(Jogador[playerid][Dinamites] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem dinamites"); 
            if(Jogador[playerid][Dinheiro] < 5000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinamites] += 4;
            Jogador[playerid][Dinheiro] -= 5000;
            EnviarDinheiroEmpresa(id, 5000); 
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou uma 4 dinamites por $5.000");
        }

        // Lockpick
        case 14:
        {
            if(Jogador[playerid][LockPick] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem lockpick's");
            if(Jogador[playerid][Dinheiro] < 3500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][LockPick] += 3;
            Jogador[playerid][Dinheiro] -= 3500;
            EnviarDinheiroEmpresa(id, 3500);
            SendClientMessage(playerid, 0x32CD32FF, "| COMPRA | Você comprou 3 lockpicks por R$3.500");
        }
    }
    pEmpresa[id][eEstoque]--;

    return 0;
}