enum CelularPInfo
{
    bool:CellAberto,
    CellTID,

    PagOcultarCelular[30],
    PagMostrarCelular[30]

};

enum UltimasLigacoes
{
    rNome[30],
    rNumero
};

new rRecente[MAX_PLAYERS];
new rCelular[MAX_PLAYERS][6][UltimasLigacoes];
new pCelularEx[MAX_PLAYERS][CelularPInfo];

new PlayerText:CelularRecente[MAX_PLAYERS][16];
new PlayerText:CelularAgendaOP[MAX_PLAYERS][3];
new PlayerText:CelularUber[MAX_PLAYERS][6];
new PlayerText:CelularCapa[MAX_PLAYERS][13];
new PlayerText:CelularHome[MAX_PLAYERS][18];
new PlayerText:CelularBanco[MAX_PLAYERS][2];
new PlayerText:CelularTransferencia[MAX_PLAYERS][9];
new PlayerText:CelularSaldo[MAX_PLAYERS][3];
new PlayerText:CelularAgenda[MAX_PLAYERS][18]; 
new PlayerText:CelularChamando[MAX_PLAYERS][4];
new PlayerText:LigacaoAndamento[MAX_PLAYERS][2];
new PlayerText:CellNot[MAX_PLAYERS][4];
new PlayerText:CelularOlx[MAX_PLAYERS][6];