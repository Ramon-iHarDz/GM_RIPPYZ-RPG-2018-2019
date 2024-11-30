#include <YSI_Coding\y_hooks>

new Utilitarios[3];
new Ammunation[5];
new SkinLoja[6];
new LojaComida[7];
new LocalAcademia[2];
new LocalSexShop;

new LojaSkinAtual[MAX_PLAYERS];
new LojaAcessorioAtual[MAX_PLAYERS];

hook OnGameModeInit()
{   
    // Utilitarios
    Utilitarios[0] = CreateDynamicCP(-27.9976,-89.6565,1003.5469, 1.0, -1, 18, -1, 30.0); 
    Utilitarios[1] = CreateDynamicCP(2.1309,-28.9420,1003.5494, 1.0, -1, 10, -1, 30.0); 
    Utilitarios[2] = CreateDynamicCP(-29.0703,-184.9570,1003.5469, 1.0, -1, 17, -1, 30.0); 

    // Ammunations
    Ammunation[0] = CreateDynamicCP(295.7430,-80.7693,1001.5156, 1.0, -1, 4, -1, 30.0); 
    // Ammunation[1] = CreateDynamicCP(295.1963,-38.5128,1001.5156, 1.0, -1, 1, -1, 30.0); 
    Ammunation[2] = CreateDynamicCP(290.0189,-109.7711,1001.5156, 1.0, -1, 6, -1, 30.0); 
    Ammunation[3] = CreateDynamicCP(308.1587,-141.2999,999.6016, 1.0, -1, 7, -1, 30.0); 
    Ammunation[4] = CreateDynamicCP(312.1510,-165.8786,999.6010, 1.0, -1, 6, -1, 30.0); 
    
    // Loja de Skins
    SkinLoja[0] = CreateDynamicCP(207.1423,-129.3286,1003.5078, 1.0, -1, 3, -1, 30.0); 
    SkinLoja[1] = CreateDynamicCP(161.4228,-83.4723,1001.8047, 1.0, -1, 18, -1, 30.0); 
    SkinLoja[2] = CreateDynamicCP(203.9232,-43.2743,1001.8047, 1.0, -1, 1, -1, 30.0); 
    SkinLoja[3] = CreateDynamicCP(206.5150,-8.1823,1001.2109, 1.0, -1, 5, -1, 30.0); 
    SkinLoja[4] = CreateDynamicCP(207.7179,-100.5150,1005.2578, 1.0, -1, 15, -1, 30.0); 
    SkinLoja[5] = CreateDynamicCP(204.5454,-159.4063,1000.5234, 1.0, -1, 14, -1, 30.0); 

    // Loja de Comidas
        // Restaurentes
    LojaComida[0] = CreateDynamicCP(450.8299,-83.6562,999.5547, 1.0, -1, 4, -1, 30.0); 

        // Pizzarias
    LojaComida[1] = CreateDynamicCP(375.6080,-119.0341,1001.4995, 1.0, -1, 5, -1, 30.0); 
        
        // Hamburgueres
    LojaComida[2] = CreateDynamicCP(369.5950,-6.1978,1001.8589, 1.0, -1, 9, -1, 30.0); 
    LojaComida[3] = CreateDynamicCP(376.5777,-67.7781,1001.5151, 1.0, -1, 10, -1, 30.0); 

        // Bares
    LojaComida[4] = CreateDynamicCP(-225.2581,1404.2600,27.7734, 1.0, -1, 18, -1, 30.0); 
    LojaComida[5] = CreateDynamicCP(496.9622,-75.7304,998.7578, 1.0, -1, 11, -1, 30.0); 

        // Donalds
    LojaComida[6] = CreateDynamicCP(379.3700,-190.4916,1000.6328, 1.0, -1, 17, -1, 30.0); 


    // Academia
    LocalAcademia[0] = CreateDynamicCP(767.4188,9.1253,1000.7100, 1.0, -1, 5, -1, 30.0); 
    LocalAcademia[1] = CreateDynamicCP(770.9636,-69.3684,1000.6563, 1.0, -1, 7, -1, 30.0); 

    // SexShop
    LocalSexShop = CreateDynamicCP(-104.0329,-22.5012,1000.7188, 1.0, -1, 3, -1, 30.0); 
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{

    // Loja de Comidas
        // Restaurantes
    if(checkpointid == LojaComida[0])
    {
        new Dialog[800];
        strcat(Dialog, "Opção\tPreço\n");
        for(new i=0; i < sizeof(Restaurante); i++)
        {
            if(Restaurante[i][QuantidadeComida] == 0) strcatEx(Dialog, "{FFFF00}        %s{FFFFFF}\n", Restaurante[i][NomeComida]);
            else strcatEx(Dialog, "{FFFFFF}%s\t{32CD32}R$%s\n", Restaurante[i][NomeComida], DinheiroSeparar(Restaurante[i][PrecoComida]));
        }
        Dialog_Show(playerid, RestauranteMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Restaurante", Dialog, "Comprar", "Fechar");
    }

        // Pizzarias
    else if(checkpointid == LojaComida[1])
    {
        new Dialog[800];
        strcat(Dialog, "Opção\tPreço\n");
        for(new i=0; i < sizeof(Pizzarias); i++)
        {
            if(Pizzarias[i][QuantidadeComida] == 0) strcatEx(Dialog, "{FFFF00}        %s{FFFFFF}\n", Pizzarias[i][NomeComida]);
            else strcatEx(Dialog, "{FFFFFF}%s\t{32CD32}R$%s\n", Pizzarias[i][NomeComida], DinheiroSeparar(Pizzarias[i][PrecoComida]));
        }
        Dialog_Show(playerid, PizzariasMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Pizzarias", Dialog, "Comprar", "Fechar");
    }

        // Hamburgueres
    else if(checkpointid == LojaComida[2] || checkpointid == LojaComida[3])
    {
        new Dialog[800];
        strcat(Dialog, "Opção\tPreço\n");
        for(new i=0; i < sizeof(Hamburgueria); i++)
        {
            if(Hamburgueria[i][QuantidadeComida] == 0) strcatEx(Dialog, "{FFFF00}        %s{FFFFFF}\n", Hamburgueria[i][NomeComida]);
            else strcatEx(Dialog, "{FFFFFF}%s\t{32CD32}R$%s\n", Hamburgueria[i][NomeComida], DinheiroSeparar(Hamburgueria[i][PrecoComida]));
        }
        Dialog_Show(playerid, HamburgueriaMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Hamburgueria", Dialog, "Comprar", "Fechar");
    }

        // Bares
    else if(checkpointid == LojaComida[4] || checkpointid == LojaComida[5])
    {
        new Dialog[800];
        strcat(Dialog, "Opção\tPreço\n");
        for(new i=0; i < sizeof(Bares); i++)
        {
            if(Bares[i][QuantidadeComida] == 0) strcatEx(Dialog, "{FFFF00}        %s{FFFFFF}\n", Bares[i][NomeComida]);
            else strcatEx(Dialog, "{FFFFFF}%s\t{32CD32}R$%s\n", Bares[i][NomeComida], DinheiroSeparar(Bares[i][PrecoComida]));
        }
        Dialog_Show(playerid, BaresMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Bar", Dialog, "Comprar", "Fechar");
    }

        // Donalds
    else if(checkpointid == LojaComida[6])
    {
        new Dialog[800];
        strcat(Dialog, "Opção\tPreço\n");
        for(new i=0; i < sizeof(Donalds); i++)
        {
            if(Donalds[i][QuantidadeComida] == 0) strcatEx(Dialog, "{FFFF00}        %s{FFFFFF}\n", Donalds[i][NomeComida]);
            else strcatEx(Dialog, "{FFFFFF}%s\t{32CD32}R$%s\n", Donalds[i][NomeComida], DinheiroSeparar(Donalds[i][PrecoComida]));
        }
        Dialog_Show(playerid, DonaldsMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Rosquinha", Dialog, "Comprar", "Fechar");
    }


    // Loja de Skins
    else if(checkpointid == SkinLoja[0] || checkpointid == SkinLoja[1] || checkpointid == SkinLoja[2] 
    || checkpointid == SkinLoja[3] || checkpointid == SkinLoja[4] || checkpointid == SkinLoja[5])
    {
        MostrarLojaSkin(playerid);
        LojaSkinAtual[playerid] = 0;
        LojaAcessorioAtual[playerid] = 0;
        AtualizarLojaSkin(playerid, 0);
    }

    // Ammunations
    else if(checkpointid == Ammunation[0] || checkpointid == Ammunation[2] || 
    checkpointid == Ammunation[3] || checkpointid == Ammunation[4])
    {
        new Dialog[800];
        strcat(Dialog, "Armas\tPreço\n");
        strcat(Dialog, "Taco de Golf\t{32CD32}R$600\n");
        strcat(Dialog, "Taco\t{32CD32}R$750\n");
        strcat(Dialog, "Pá\t{32CD32}R$300\n");
        //strcat(Dialog, "Granadas\t{32CD32}R$1.900\n");
        strcat(Dialog, "9mm\t{32CD32}R$2.500\n");
        strcat(Dialog, "9mm Silenciada\t{32CD32}R$3.800\n");
        strcat(Dialog, "Shotgun\t{32CD32}R$3.000\n");
        strcat(Dialog, "Combat Shotgun\t{32CD32}R$3.500\n");
        strcat(Dialog, "MP5\t{32CD32}R$2.000\n");
        strcat(Dialog, "Sniper\t{32CD32}R$3.000\n");
        strcat(Dialog, "Rifle\t{32CD32}R$2.000\n");
        strcat(Dialog, "Desert\t{32CD32}R$1.500\n");
        strcat(Dialog, "Sawnoff Shotgun\t{32CD32}R$1.500\n");
        strcat(Dialog, "M4\t{32CD32}R$3.600\n");
        strcat(Dialog, "Dinamites\t{32CD32}R$5.000 [4 Unidades]\n"); 
        strcat(Dialog, "Lockpick\t{32CD32}R$3.500 [3 Unidades]\n"); 
        Dialog_Show(playerid, AmmunationMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Ammunation", Dialog, "Comprar", "Fechar");
    }

    // Loja de Utilitarios
    else if(checkpointid == Utilitarios[0] || checkpointid == Utilitarios[1] || checkpointid == Utilitarios[2])
    {
        new Dialog[800];
        strcat(Dialog, "Item\tPreço\n");
        //strcat(Dialog, "Comprar Celular\t{32CD32}R$2.500\n");
        strcat(Dialog, "Creditos\t{FF8C00}-\n"); 
        strcat(Dialog, "Mochila\t{32CD32}R$30.000\n");
        strcat(Dialog, "Gps\t{32CD32}R$5.000\n");
        strcat(Dialog, "MP3\t{32CD32}R$3.000\n");
        strcat(Dialog, "Sementes\t{32CD32}$3.000\n");
        strcat(Dialog, "Água\t{FF8C00}-\n");
        strcat(Dialog, "Kit de Reparos\t{32CD32}R$1.500 Und\n");
        strcat(Dialog, "Relogio UP\t{32CD32}R$20.000\n");
        strcat(Dialog, "Galão de Combustível\t{32CD32}R$2.000\n");
        strcat(Dialog, "Câmera Fotográfica\t{32CD32}R$1.100\n");
        strcat(Dialog, "Raspberry\t{32CD32}R$1.500 Und\n");
        strcat(Dialog, "Tranca de Veículo\t{32CD32}R$5.000\n"); 
        Dialog_Show(playerid, UtilitariosMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Loja de Utilitários", Dialog, "Selecionar", "Fechar");
    }

    else if(checkpointid == LocalAcademia[0] || checkpointid == LocalAcademia[1])
    {
        new Dialog[200];
        strcat(Dialog, "Estilo\tMensalidade\n");
        strcat(Dialog, "Boxe\t{32CD32}R$950\n");
        strcat(Dialog, "KungFu\t{32CD32}R$950\n");
        strcat(Dialog, "Knee Head\t{32CD32}R$950\n");
        strcat(Dialog, "Grab Kick\t{32CD32}R$950\n");
        strcat(Dialog, "Cotovelada\t{32CD32}R$950\n");
        strcat(Dialog, "{FF0000}Cancelar Plano");
        Dialog_Show(playerid, AcademiaPlano, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Academia", Dialog, "Selecionar", "Fechar");   
    }

    else if(checkpointid == LocalSexShop)
    {
        new Dialog[228];
        strcat(Dialog, "Item\tPreço\n");
        strcat(Dialog, "Dildo Roxo\t{32CD32}R$1.500\n");
        strcat(Dialog, "Dildo\t{32CD32}R$1.200\n");
        strcat(Dialog, "Vibrador\t{32CD32}R$1.700\n");
        strcat(Dialog, "Dildo Branco\t{32CD32}R$1.100");
        Dialog_Show(playerid, SexoShopLoJa, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}SexShop", Dialog, "Selecionar", "Fechar");
    }
    return 1;
}