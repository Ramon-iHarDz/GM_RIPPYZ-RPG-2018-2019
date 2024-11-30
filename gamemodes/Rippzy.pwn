
#include <a_samp>
#include <a_mysql>
#include <a_http>
#include <sscanf2>
#include <easyDialog>
#include <streamer>
#include <zcmd>

#include <YSI_Coding\y_hooks> 

//#include "../include/gl_common.inc"

#include <strlib>
#include <PaintGet>
#include <mapandreas>
#include <WeaponCheat>
#include <VeiculoCheck>
#include <NomeObjetos>
#include <playerzone>
#include <VeiculoCor>
#include <DataConvert>
#include <crashdetect>
#include <attachments>
#include <CTime>
#include <pause>
//#include <geolocation>
#include <VehiclePartPosition>

main() {
    print("[Rippzy:Servidor] Servidor foi carregado por completo."); 
	print("[Rippzy:Servidor] Copyright - Rippzy RP."); // e2b960
}

// Variaveis de Funções 
#include "../Dependencias/Configuracao/Variaveis" // Todos os enums de todas as Funções
#include "../Dependencias/Configuracao/Definicoes" // Configurações / Macros

//Modos
#include "../Dependencias/Modos/Variaveis"
#include "../Dependencias/Modos/ModoGeral"
//.
#include "../Dependencias/Modos/Counter/Counter"
#include "../Dependencias/Modos/Arena/Arena"

// Atualizaï¿½ï¿½es
#include "../Dependencias/Jogador/Informacoes/SalvarConta" // Salvar Conta do Usuário
#include "../Dependencias/Jogador/Informacoes/Jogador_Update" // Atualizar informações do Jogador
#include "../Dependencias/Jogador/Informacoes/Veiculo_Update" // Atualizar informações do Veiculo
#include "../Dependencias/Jogador/Informacoes/Hora" // Atualizar Relogio e Tempo do Jogador
 
// Jogadores
#include "../Dependencias/Jogador/Comandos/Comandos" // Comandos dos Jogadores
#include "../Dependencias/Jogador/Comandos/Ranks" // Top Ranks
#include "../Dependencias/Jogador/Dialogs/Dialogs" // Callbacks dos Jogadores
#include "../Dependencias/Jogador/Dialogs/Ajuda" // Lista de ajuda do /ajuda
#include "../Dependencias/Jogador/Informacoes/Tunagem" // Sistema de tunagens
#include "../Dependencias/Jogador/Dialogs/Garagem" // Callbacks do /garagem
#include "../Dependencias/Jogador/Dialogs/PortaMalas" // Porta Malas
//#include "../Dependencias/Jogador/Comandos/Neon" // Sistema de Neon
#include "../Dependencias/Jogador/Comandos/Comandos_VIP"

// Plugins
#include "../Dependencias/Geral/Plugins/sampmailjs"

// Configurações - Funções - Atualizaï¿½ï¿½o do Servidor
#include "../Dependencias/Configuracao/Funcao" //Funções
#include "../Dependencias/Configuracao/UpdateServidor" //Atualizaï¿½ï¿½o do Servidor

//Admin
#include "../Dependencias/Admin/Admin" // Comandos em geral da administraï¿½ï¿½o
#include "../Dependencias/Admin/Chamadas/Hooks" // Todas as Callbacks
#include "../Dependencias/Admin/Chamadas/Dialogs" // Todas as dialogs
//#include "../Dependencias/Admin/Utilitarios/Hack" // Hack's admins
//#include "../Dependencias/Admin/Utilitarios/Fogos"
#include "../Dependencias/Admin/Utilitarios/Desenvolvedor"
#include "../Dependencias/Admin/Utilitarios/Ovo"

//Conexões
#include "../Dependencias/Conexao/Discord/Variavel"
//#include "../Dependencias/Geral/Plugins/DiscordPlugin"
#include "../Dependencias/Conexao/Conexoes"
#include "../Dependencias/Conexao/Discord/Comandos"
#include "../Dependencias/Conexao/Discord/Funcao"
#include "../Dependencias/Conexao/Discord/Discord"
#include "../Dependencias/Conexao/Discord/Discord_Hooks"
#include "../Dependencias/Conexao/Discord/Denuncias"
#include "../Dependencias/Conexao/Discord/ChatVip"

//Som Automotivo
#include "../Dependencias/Jogador/Informacoes/Som" // Som no veiculo

//Utilitï¿½rios
#include "../Dependencias/Jogador/Utilitarios/Gps" // Sistema de /Gps

//Ativaï¿½ï¿½o VIP
#include "../Dependencias/Geral/AtivacaoCoins/Ativacao"

//AntiAFK
#include "../Dependencias/Geral/AntiAFK/AntiAFK" // Sistema em Si
#include "../Dependencias/Geral/AntiAFK/Hooks/GeradorAFK" // Gerar Cï¿½digo do AntiAFK
#include "../Dependencias/Geral/AntiAFK/Modulos/TelaAFK" // Textdraw do AntiAFK

//Prisï¿½o
#include "../Dependencias/Geral/Prisao/prisao_modulo"
#include "../Dependencias/Geral/Prisao/prisao_hooks"

//Login
#include "../Dependencias/Geral/Login/login_modulo"
#include "../Dependencias/Geral/Login/login_hook"

//Registro
#include "../Dependencias/Geral/Registro/registro_modulo"
#include "../Dependencias/Geral/Registro/registro_hook"

//Sistema de Casa
#include "../Dependencias/Geral/Casas/Casa"
#include "../Dependencias/Geral/Casas/Hooks/Funcao"
#include "../Dependencias/Geral/Casas/Hooks/Dialogs"

//Hospital
#include "../Dependencias/Geral/Hospital/Funcao"
#include "../Dependencias/Geral/Hospital/Hospital"

//Prefeitura
#include "../Dependencias/Geral/Prefeitura/Dialogs/Dialogs"
#include "../Dependencias/Geral/Prefeitura/Prefeitura"

//Airdrop
#include "../Dependencias/Geral/AirDrop/Presentes"
#include "../Dependencias/Geral/AirDrop/Airdrop"
#include "../Dependencias/Geral/AirDrop/AirDropAdmin/DropAdmin"

//Caixas Boxs
#include "../Dependencias/Geral/Caixas/Presentes"
#include "../Dependencias/Geral/Caixas/Caixas"

//Cilindro
#include "../Dependencias/Geral/Cilindro/Modulos/CilindroText"
#include "../Dependencias/Geral/Cilindro/Cilindro"

//AssaltoLojinha
#include "../Dependencias/Geral/Lojinha/Construcao/Loja"
#include "../Dependencias/Geral/Lojinha/Modulos/AssaltoInfo"
#include "../Dependencias/Geral/Lojinha/Lojinha"

//Eventos
#include "../Dependencias/Geral/Eventos/Eventos"
#include "../Dependencias/Geral/Eventos/Derby"
//
#include "../Dependencias/Geral/Eventos/AmongUs/Variaveis"
#include "../Dependencias/Geral/Eventos/AmongUs/Funcao"
#include "../Dependencias/Geral/Eventos/AmongUs/Admin"
#include "../Dependencias/Geral/Eventos/AmongUs/Among"
#include "../Dependencias/Geral/Eventos/AmongUs/Painel"
//
#include "../Dependencias/Geral/Eventos/Corrida/Variavel"
#include "../Dependencias/Geral/Eventos/Corrida/Corrida"
//
#include "../Dependencias/Geral/Eventos/Setembro"
//
#include "../Dependencias/Geral/Eventos/Jason"
#include "../Dependencias/Geral/Eventos/DiscordEventos"

//Orelhï¿½o	  
#include "../Dependencias/Geral/TelefonePublico/Telefone"

//Enquetes
#include "../Dependencias/Geral/Enquetes/Modulos"
#include "../Dependencias/Geral/Enquetes/Enquete"

//Camera Livre
#include "../Dependencias/Geral/CameraLivre/Camera"

//ï¿½rea VIP
#include "../Dependencias/Geral/AreaVIP/AreaVIP"

//Broadcast
#include "../Dependencias/Geral/BroadCast/Broadcast" 

//Configuraï¿½ï¿½o
#include "../Dependencias/Geral/Configuracao/Config"

//Lotï¿½rica
#include "../Dependencias/Geral/Loterica/Modulos/LoteriaDraw"
#include "../Dependencias/Geral/Loterica/Modulos/LoteriaApostaDraw"
#include "../Dependencias/Geral/Loterica/Loteria"

//Mochila
#include "../Dependencias/Geral/Mochila/Mochila"

//Pï¿½tio de Veículos
#include "../Dependencias/Geral/Patio/Patio"

//Desmanche
#include "../Dependencias/Geral/Desmanche/Construcao"
#include "../Dependencias/Geral/Desmanche/Desmanche"

//Pontos de Bike
#include "../Dependencias/Geral/Bikes/Bikes"

//Objetos
#include "../Dependencias/Geral/Objetos/Objetos"

//Porte de Armas
#include "../Dependencias/Geral/PorteDeArmas/Porte_Modulos"
#include "../Dependencias/Geral/PorteDeArmas/Porte"

//Inauguraï¿½ï¿½o
#include "../Dependencias/Geral/Inauguracao/Inauguracao_Modulos"
#include "../Dependencias/Geral/Inauguracao/Inauguracao"

//Recompensas
#include "../Dependencias/Geral/Recompensas/Recompensas"

//Evento
/*#include "../Dependencias/Geral/Evento/Construcao"
#include "../Dependencias/Geral/Evento/Evento"*/
//#include "../Dependencias/Geral/Evento/Praia"
//#include "../Dependencias/Geral/Evento/Texto"
//#include "../Dependencias/Geral/Evento/Skate"

#include "../Dependencias/Geral/Radios/Radios"

//Aeroporto
#include "../Dependencias/Geral/Aeroporto/Aeroporto"

//Mï¿½fia
#include "../Dependencias/Geral/Mafia/Usuario" 
#include "../Dependencias/Geral/Mafia/Mafia"
#include "../Dependencias/Geral/Mafia/Vendedores"

//Sistema de Mï¿½veis
#include "../Dependencias/Geral/Moveis/Loja/Modulos/Menu"
#include "../Dependencias/Geral/Moveis/Loja/Variaveis"
#include "../Dependencias/Geral/Moveis/Loja/Funcao"
#include "../Dependencias/Geral/Moveis/Loja/Dialog"
#include "../Dependencias/Geral/Moveis/Loja/Interior"
#include "../Dependencias/Geral/Moveis/Loja/Loja"
#include "../Dependencias/Geral/Moveis/Dialog"
#include "../Dependencias/Geral/Moveis/Funcao"
#include "../Dependencias/Geral/Moveis/Moveis"

//Pedido Casamento ou Namoro
#include "../Dependencias/Geral/Casamento/Backup/Construcao/Local"
#include "../Dependencias/Geral/Casamento/Backup/Casamento"
#include "../Dependencias/Geral/Casamento/Casamento"

//iRippzy
#include "../Dependencias/Geral/iRippzy/Interior"
#include "../Dependencias/Geral/iRippzy/iRippzy"

//Hobbys
#include "../Dependencias/Geral/Hobbys/Produtor/Mafia/Modulos/AssaltoTempo"
#include "../Dependencias/Geral/Hobbys/Produtor/Mafia/Assaltante"

#include "../Dependencias/Geral/Hobbys/Produtor/Produtor"
#include "../Dependencias/Geral/Hobbys/Produtor/Interior"

//Pedï¿½gio
//#include "../Dependencias/Geral/Pedagios/Pedagio"
//#include "../Dependencias/Geral/Pedagios/Pedagios"

//Sistema de Celular
#include "../Dependencias/Geral/Celular/Variavel"
#include "../Dependencias/Geral/Celular/Funcao"
#include "../Dependencias/Geral/Celular/Celular"
#include "../Dependencias/Geral/Celular/Modulos/CelularCapa"
#include "../Dependencias/Geral/Celular/Modulos/CelularHome"
#include "../Dependencias/Geral/Celular/Modulos/CelularBanco"
#include "../Dependencias/Geral/Celular/Modulos/CelularSaldo"
#include "../Dependencias/Geral/Celular/Modulos/CelularTransferencia"
#include "../Dependencias/Geral/Celular/Modulos/CelularAgenda"
#include "../Dependencias/Geral/Celular/Modulos/CelularLigacao"
#include "../Dependencias/Geral/Celular/Modulos/CelularUber"
#include "../Dependencias/Geral/Celular/Modulos/CelularNotificacao"
#include "../Dependencias/Geral/Celular/Modulos/CelularOlx"

//Sistema de Empresa
#include "../Dependencias/Geral/Empresas/Empresa" // Sistema em si
#include "../Dependencias/Geral/Empresas/Hooks/EmpresaAdmin" // Admin
#include "../Dependencias/Geral/Empresas/Hooks/Funcoes" // Todas as Funções de pegar id etc..
#include "../Dependencias/Geral/Empresas/Compras/Compra" // Sistema de compras dentro das lojas
#include "../Dependencias/Geral/Empresas/Hooks/EmpresaDialog"

//#include "../Dependencias/Geral/Empresas/Fabricas/Interior"
//#include "../Dependencias/Geral/Empresas/Fabricas/Fabricas"

#include "../Dependencias/Geral/Empresas/Hotel/Hotel"

// Sistema de Fï¿½bricas
#include "../Dependencias/Geral/Empresas/Fabricas/Fabricas" // Sistema em si
#include "../Dependencias/Geral/Empresas/Fabricas/Funcao"
#include "../Dependencias/Geral/Empresas/Fabricas/Dialog/Dialog"
#include "../Dependencias/Geral/Empresas/Fabricas/Construcao/Construcao"
#include "../Dependencias/Geral/Empresas/Fabricas/Producao"
#include "../Dependencias/Geral/Empresas/Fabricas/ProducaoConce"
#include "../Dependencias/Geral/Empresas/Fabricas/Admin/FabricaAdmin"


#include "../Dependencias/Geral/Empresas/Compras/Lojas/Ammunation"
#include "../Dependencias/Geral/Empresas/Compras/Lojas/Utilitarios"
#include "../Dependencias/Geral/Empresas/Compras/Lojas/Skin"
#include "../Dependencias/Geral/Empresas/Compras/Lojas/Comida"
#include "../Dependencias/Geral/Empresas/Compras/Lojas/Academia"
#include "../Dependencias/Geral/Empresas/Compras/Lojas/SexShop"
#include "../Dependencias/Geral/Empresas/Compras/Modulos/LojaAcessorio"
#include "../Dependencias/Geral/Empresas/Compras/Modulos/LojaSkin"

//Textdraws
#include "../Dependencias/Geral/Textdraws/ErroTelaLogin" // Mensagem de Senha Incorreta etc..
#include "../Dependencias/Geral/Textdraws/AlertaAdmin" // Mensagens de cnn e ann admin
#include "../Dependencias/Geral/Textdraws/RespawnAdmin" // Mensagem na tela de respawn admin RVS
#include "../Dependencias/Geral/Textdraws/Velocimetro" // Velocimetro
#include "../Dependencias/Geral/Textdraws/RadarNotificacao" // Mensagem ao passar pelo radar
#include "../Dependencias/Geral/Textdraws/Abastecimento" // Textdraw de abastecimento dos postos
#include "../Dependencias/Geral/Textdraws/MensagemBaixo" // Mensagem na tela embaixo  
#include "../Dependencias/Geral/Textdraws/LogoMarca" // Logo Marca RC
#include "../Dependencias/Geral/Textdraws/Localizador" // Localizador da PM

//Profissï¿½es
#include "../Dependencias/Profissoes/Comandos/ComandosProf" // Comando das profissï¿½es
//
#include "../Dependencias/Profissoes/Gari/Variaveis"
#include "../Dependencias/Profissoes/Gari/Funcao"
#include "../Dependencias/Profissoes/Gari/Lixo/Lixo"
#include "../Dependencias/Profissoes/Gari/Trabalhador/Trabalho"
#include "../Dependencias/Profissoes/Gari/Trabalhador/Jogador"
#include "../Dependencias/Profissoes/Gari/Modulos/Modulo_Gari"
//
#include "../Dependencias/Profissoes/Detran/DetranNormal" // Pagar Multas e ver estado do Veículo
//
#include "../Dependencias/Profissoes/Uber/Modulos/UberTxd" // Textdraw
#include "../Dependencias/Profissoes/Uber/Uber"
//
#include "../Dependencias/Profissoes/Policia/Policia" // Sistema em si
#include "../Dependencias/Profissoes/Policia/Hooks/Chamadas/Funcoes" // CallBacks de Desalgemar, timers etc..
#include "../Dependencias/Profissoes/Policia/Hooks/Armario/Armario"
#include "../Dependencias/Profissoes/Policia/Hooks/Veiculos/Veiculos"
//#include "../Dependencias/Profissoes/Policia/Modulos/PainelPolicial" //Textdraw do painel policial
#include "../Dependencias/Profissoes/Policia/Modulos/Abordagem" //Textdraw da abordagem
#include "../Dependencias/Profissoes/Policia/Hooks/Armario/Modulos/ArmarioTxd" //Uniformes
#include "../Dependencias/Profissoes/Policia/Fianca/Fianca" // Sistema de Fianï¿½a
#include "../Dependencias/Profissoes/Policia/Patente/Modulos/Medalha" 
#include "../Dependencias/Profissoes/Policia/Patente/Patente" // Sistema de Patente

//
#include "../Dependencias/Profissoes/Onibus/Motorista" // Sistema em si
#include "../Dependencias/Profissoes/Onibus/Modulos/MensagemOnibus" // Mensagem de embarque
#include "../Dependencias/Profissoes/Onibus/Admin/Hooks/Funcoes"
#include "../Dependencias/Profissoes/Onibus/Admin/Paradas/Paradas" // Sistema para adicionar paradas
#include "../Dependencias/Profissoes/Onibus/Admin/Rotas/CriarRotas" // Sistema para adicionar rotas
//
#include "../Dependencias/Profissoes/UberEats/Funcao" // Variaveis e algumas Funções
#include "../Dependencias/Profissoes/UberEats/UberEats" // Sistema em si
//
#include "../Dependencias/Profissoes/Mecanico/Funcao"
#include "../Dependencias/Profissoes/Mecanico/Hooks/Compra"
#include "../Dependencias/Profissoes/Mecanico/Hooks/Veiculo"
#include "../Dependencias/Profissoes/Mecanico/Mecanico"
//
#include "../Dependencias/Profissoes/Plantador/Variaveis" // Vï¿½riaveis
#include "../Dependencias/Profissoes/Plantador/Funcao" // Funções
#include "../Dependencias/Profissoes/Plantador/Plantador" // 
#include "../Dependencias/Profissoes/Plantador/Compra/Compra" // Sistema de Compra
#include "../Dependencias/Profissoes/Plantador/Plantacao/Plantacao" // Sistema de Plantaï¿½ï¿½o
//
#include "../Dependencias/Profissoes/Transportador/Variaveis" // Vï¿½riaveis
#include "../Dependencias/Profissoes/Transportador/Funcao" // Funções
#include "../Dependencias/Profissoes/Transportador/Transportador" // Carregamentos
#include "../Dependencias/Profissoes/Transportador/Trabalho/Jogador" // Sistema do Jogador
#include "../Dependencias/Profissoes/Transportador/Trabalho/Trabalho" // Sistema de Entregas
//
#include "../Dependencias/Profissoes/Lenhador/Variavel" // Vï¿½riaveis
//#include "../Dependencias/Profissoes/Lenhador/Funcao" // Vï¿½riaveis
#include "../Dependencias/Profissoes/Lenhador/Lenhador" // 'Sistema em sï¿½
//
#include "../Dependencias/Profissoes/Advogado/Advogado" // Sistema em si
//
#include "../Dependencias/Profissoes/LadraoDeVeiculo/Variavel"
#include "../Dependencias/Profissoes/LadraoDeVeiculo/Funcao"
#include "../Dependencias/Profissoes/LadraoDeVeiculo/Ladrao"
#include "../Dependencias/Profissoes/LadraoDeVeiculo/Modulos/LadraoText"
#include "../Dependencias/Profissoes/LadraoDeVeiculo/Modulos/TempoText"
//
#include "../Dependencias/Profissoes/Paramedico/Paramedico"
//
#include "../Dependencias/Profissoes/Ourives/Variavel"
#include "../Dependencias/Profissoes/Ourives/Chamadas"
#include "../Dependencias/Profissoes/Ourives/Ourives"
//
#include "../Dependencias/Profissoes/Bombeiro/Bombeiro"
//
#include "../Dependencias/Profissoes/MotoristaDeCarroForte/Variavel"
#include "../Dependencias/Profissoes/MotoristaDeCarroForte/CarroForte"
//
#include "../Dependencias/Profissoes/Maquinista/Variavel"
#include "../Dependencias/Profissoes/Maquinista/Maquinista"
//
#include "../Dependencias/Profissoes/Assassino/Assassino"
//
//#include "../Dependencias/Profissoes/Assaltante/Assaltante"
//
#include "../Dependencias/Profissoes/Corregedoria/Corregedoria"
//
#include "../Dependencias/Profissoes/Petroleiro/Variavel"
#include "../Dependencias/Profissoes/Petroleiro/Petroleiro"
//
#include "../Dependencias/Profissoes/Meteorologista/Variavel"
#include "../Dependencias/Profissoes/Meteorologista/Meteorologista"
//
#include "../Dependencias/Profissoes/Exercito/Variavel"
#include "../Dependencias/Profissoes/Exercito/Exercito"
//
#include "../Dependencias/Profissoes/Aeronautica/Variavel" 
#include "../Dependencias/Profissoes/Aeronautica/Aeronautica" 
//
#include "../Dependencias/Profissoes/Marinha/Variavel" 
#include "../Dependencias/Profissoes/Marinha/Marinha" 
#include "../Dependencias/Profissoes/Marinha/Construcao" 
//
#include "../Dependencias/Profissoes/Piloto/Variavel"
#include "../Dependencias/Profissoes/Piloto/Piloto"
//
#include "../Dependencias/Profissoes/EntregadorDeMoveis/Variavel"
#include "../Dependencias/Profissoes/EntregadorDeMoveis/Modulos/Info"
#include "../Dependencias/Profissoes/EntregadorDeMoveis/Entregador"
#include "../Dependencias/Profissoes/EntregadorDeMoveis/Entregando"
//
#include "../Dependencias/Profissoes/Acougueiro/Variavel"
#include "../Dependencias/Profissoes/Acougueiro/Transporte/CarneTransporte"
#include "../Dependencias/Profissoes/Acougueiro/Interior"
#include "../Dependencias/Profissoes/Acougueiro/Acougueiro" 
//
#include "../Dependencias/Profissoes/Pericia/Pericia"
//
#include "../Dependencias/Profissoes/Eletricista/Variavel"
#include "../Dependencias/Profissoes/Eletricista/Postes"
#include "../Dependencias/Profissoes/Eletricista/Eletricista"
//
#include "../Dependencias/Profissoes/Leiteiro/Leiteiro"
//
#include "../Dependencias/Profissoes/ProdutorDaMafia/Produtor"
//
#include "../Dependencias/Profissoes/Mergulhador/Construcao"
#include "../Dependencias/Profissoes/Mergulhador/Mergulhador"
//
#include "../Dependencias/Profissoes/HotDog/HotDog"
//
#include "../Dependencias/Profissoes/Terrorista/Terrorista"
//
#include "../Dependencias/Profissoes/ProdutorDeFrutas/Construcao"
#include "../Dependencias/Profissoes/ProdutorDeFrutas/Frutas"
//
#include "../Dependencias/Profissoes/PizzaDelivery/PizzaDelivery"
//
#include "../Dependencias/Profissoes/EntregadorConcreto/Entregador"
//
#include "../Dependencias/Profissoes/TransportadorDeEletronicos/Transportador"
//
#include "../Dependencias/Profissoes/Fazendeiro/Fazendeiro"

//Recursos
//#include "../Dependencias/Geral/Recursos/ArmaH" // Fix bug do H tirar e pegar arma
#include "../Dependencias/Geral/Recursos/ArmaG" // Remover arams OPS do G
#include "../Dependencias/Geral/Recursos/Localizacao" // Sistema de Localizar ( /Localizar )
#include "../Dependencias/Geral/Recursos/AcessoCodigo" // Sistema de Cï¿½digo
#include "../Dependencias/Geral/Recursos/BarraDeProgresso" // Sistema de Progresso
#include "../Dependencias/Geral/Recursos/DropArmas" // Sistema de Progresso
#include "../Dependencias/Geral/Recursos/Skate" // Sistema de Skate

//Banco Sistema
#include "../Dependencias/Geral/Banco/Modulos/BancoCapa"
#include "../Dependencias/Geral/Banco/Modulos/BancoHome"
#include "../Dependencias/Geral/Banco/Modulos/BancoSaque"
#include "../Dependencias/Geral/Banco/Modulos/BancoDeposito"
#include "../Dependencias/Geral/Banco/Modulos/BancoTransferir"
#include "../Dependencias/Geral/Banco/Hooks/Dialogs"

#include "../Dependencias/Geral/Banco/Cofre/Interior"
#include "../Dependencias/Geral/Banco/Cofre/Cofre"

// #include "../Dependencias/Geral/Banco/Apostas/Estrelas"
#include "../Dependencias/Geral/Banco/Banco"


// Sistemas de Voips
#include "../Dependencias/Geral/Voips/Microfone" // Sistema de Voip
#include "../Dependencias/Geral/Voips/Voips" // Sistema de Voips

//Elevador
#include "../Dependencias/Geral/Elevador/ElevadorCidade" // Sistema em si
#include "../Dependencias/Geral/Elevador/ElevadorPraia" // Sistema em si

//Caixa Eletronico
#include "../Dependencias/Geral/Caixa_Eletronico/Caixa" // Sistema em si

//Acessorios
#include "../Dependencias/Geral/Acessorios/Acessorios" // Sistema Admin e /Acessorio

//Keypad
#include "../Dependencias/Geral/Keypad/Keypad"

//Clima
#include "../Dependencias/Geral/Clima/Clima" // Sistema de Climas

//Status
#include "../Dependencias/Geral/Status/Status" // Sistema em si
#include "../Dependencias/Geral/Status/Modulos/StatusDraw" // TextDraw do Status
#include "../Dependencias/Geral/Status/Doencas/Doencas" // Sistema em si

//Radar
#include "../Dependencias/Geral/Radar/Radar" // Sistema em si

//Concessionaria
#include "../Dependencias/Geral/Concessionaria/Modulos/ConceDraw"
#include "../Dependencias/Geral/Concessionaria/Hooks/ConceFuncao"
#include "../Dependencias/Geral/Concessionaria/Hooks/Dialogs"
#include "../Dependencias/Geral/Concessionaria/Hooks/Funcao"
#include "../Dependencias/Geral/Concessionaria/Admin/Admin"
#include "../Dependencias/Geral/Concessionaria/Concessionaria"
#include "../Dependencias/Geral/Concessionaria/Revenda/Revenda"
//#include "../Dependencias/Geral/Concessionaria/Construcao/LosSantos"
#include "../Dependencias/Geral/Concessionaria/Construcao/LosSantosEx"

//CarMax
//#include "../Dependencias/Mapa/Locais/VeiculosVenda" // CarMax venda de veiculos

//Gasolina
#include "../Dependencias/Geral/Gasolina/Gasolina" // Sistema de Gasolina
#include "../Dependencias/Geral/Gasolina/Combustivel" // Sistema de abastecimento

//Animaï¿½ï¿½o
#include "../Dependencias/Jogador/Comandos/Animacoes" // Lista e Animaï¿½ï¿½es

//Sistema de Bases
#include "../Dependencias/Geral/Bases/Usuarios/Modulos"
#include "../Dependencias/Geral/Bases/Funcao"
#include "../Dependencias/Geral/Bases/Bases"
#include "../Dependencias/Geral/Bases/Usuarios/Membros"
#include "../Dependencias/Geral/Bases/Usuarios/Fabricacao"
#include "../Dependencias/Geral/Bases/Admin/CriarBase"
#include "../Dependencias/Geral/Bases/Admin/Admin"
#include "../Dependencias/Geral/Bases/Construcoes/ElQuebrados1"
#include "../Dependencias/Geral/Bases/Construcoes/ElQuebrados2"
#include "../Dependencias/Geral/Bases/Construcoes/InteriorBase"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturas1"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturas2"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturasTrem"
#include "../Dependencias/Geral/Bases/Construcoes/LosSantosFazenda"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturasConce"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturasArena"
#include "../Dependencias/Geral/Bases/Construcoes/LasVenturasBug"
#include "../Dependencias/Geral/Bases/Construcoes/LosSantosPetrol"
#include "../Dependencias/Geral/Bases/Construcoes/LosSantosPizza"

//Contruï¿½ï¿½es
#include "../Dependencias/Mapa/Locais/Locais" // Entrada e Saida de locais pï¿½blicos
#include "../Dependencias/Mapa/Locais/Agencia" // Agencia de Empregos
#include "../Dependencias/Mapa/Locais/AutoEscola" // Auto Escola
//
#include "../Dependencias/Mapa/Construcoes/Policia/Interior" // Interior do Departamento
#include "../Dependencias/Mapa/Construcoes/Policia/ExteriorLS" // ï¿½rea externa da dp LS
//
#include "../Dependencias/Mapa/Construcoes/Bombeiro/BombeiroHQ" // HQ de bombeiro em las venturas
#include "../Dependencias/Mapa/Construcoes/Bombeiro/InteriorBombeiro" // Interior da HQ de bombeiro
//
#include "../Dependencias/Mapa/Construcoes/Hospital/Interior" // Interior do Hospital
#include "../Dependencias/Mapa/Construcoes/Diversos/Postos" // Adicionando postos sem explosï¿½es
#include "../Dependencias/Mapa/Construcoes/Banco/Banco" // Interior do Banco
// #include "../Dependencias/Mapa/Construcoes/CarMax/CarMaxConstrucao" // Exterior do CarMax
#include "../Dependencias/Mapa/Construcoes/AutoEscola/AutoEscolaConstrucao" // Interior da Auto Escola
#include "../Dependencias/Mapa/Construcoes/Detran/DetranInterior" // Interior do Detran
#include "../Dependencias/Mapa/Construcoes/Apartamento/Apartamento" // Interior dos apartamentos
#include "../Dependencias/Mapa/Construcoes/Diversos/BaseMafiaMont" // Construï¿½ï¿½o da Mafia Mont
#include "../Dependencias/Mapa/Construcoes/Diversos/HqOnibus" // Construï¿½ï¿½o da HQ de motorista de onibus
#include "../Dependencias/Mapa/Construcoes/Diversos/Maquinas" // Remover Maquina de Comida
#include "../Dependencias/Mapa/Construcoes/Fazenda/Fazenda" // Construï¿½ï¿½o fazenda ponto zero
#include "../Dependencias/Mapa/Construcoes/Fazenda/FazendaMafia" // Construï¿½ï¿½o plantaï¿½ï¿½o de maconha
#include "../Dependencias/Mapa/Construcoes/Diversos/InteriorAgencia" // Adicionar portas no interior da agï¿½ncia de empregos
#include "../Dependencias/Mapa/Construcoes/Diversos/BecoEmLs" // Construï¿½ï¿½o da mafia em los santos
#include "../Dependencias/Mapa/Construcoes/Diversos/BecoNoMorro" // Construï¿½ï¿½o da mafia no morro
#include "../Dependencias/Mapa/Construcoes/Diversos/DiscoVoador" // Disco voador maze
#include "../Dependencias/Mapa/Construcoes/Mecanica/Mecanica" // Construï¿½ï¿½o da mecanica na Fazenda
// #include "../Dependencias/Mapa/Construcoes/Diversos/MafiaFavela" // Construï¿½ï¿½o de pegar profissï¿½o mafia 
#include "../Dependencias/Mapa/Construcoes/Diversos/Prefeitura" // Construï¿½ï¿½o dentro da prefeitura
#include "../Dependencias/Mapa/Construcoes/Diversos/ConstrucaoStaff" // Construï¿½ï¿½o no spawn para staff
#include "../Dependencias/Mapa/Construcoes/Diversos/Lenhador" // Construï¿½ï¿½o na HQ de lenhador LS 
#include "../Dependencias/Mapa/Construcoes/Diversos/PraiaConstrucao" // Construï¿½ï¿½o na Praia LS
#include "../Dependencias/Mapa/Construcoes/Diversos/PrefeituraLS" // Nova prefeitura LS
//#include "../Dependencias/Mapa/Construcoes/Diversos/HqPetroleiro" // HQ Petroleiro
#include "../Dependencias/Mapa/Construcoes/Diversos/AreaVIP" // Interior Area VIP
#include "../Dependencias/Mapa/Construcoes/Diversos/AeroportoLS" // Contruï¿½ï¿½o Aeroporto
#include "../Dependencias/Mapa/Construcoes/Diversos/PistaBs" // Pista de Aviï¿½o em Bayside
#include "../Dependencias/Mapa/Construcoes/Diversos/RodaGigante" // Roda Gigante LS
//#include "../Dependencias/Mapa/Construcoes/Diversos/CubosAgencia" // Cubos na Agï¿½ncia
#include "../Dependencias/Mapa/Construcoes/Diversos/247Agencia" // Nova 24/7 na agï¿½ncia
//
#include "../Dependencias/Mapa/Construcoes/Meteorologista/Antenas"
#include "../Dependencias/Mapa/Construcoes/Meteorologista/Meteorologista"
#include "../Dependencias/Mapa/Construcoes/MundoAberto/Loterica"
//
//#include "../Dependencias/Mapa/Construcoes/Garagens/GaragemLS"
#include "../Dependencias/Mapa/Construcoes/Diversos/Transportadora"
#include "../Dependencias/Mapa/Construcoes/Diversos/LasVenturasBaseMafia"
//#include "../Dependencias/Mapa/Construcoes/Diversos/FecharBombs"
#include "../Dependencias/Mapa/Construcoes/Diversos/SanFierroProducao" // Producao SF


public OnPlayerRequestClass(playerid, classid)
{
    if(Jogador[playerid][Logado] == false) return 1;
	return 1;
}

public OnPlayerConnect(playerid)
{
	if(IsPlayerNPC(playerid)) return 1;
	SetPlayerColor(playerid, 0xFFFFFFFF);
	new Versao[24];
    GetPlayerVersion(playerid, Versao, sizeof(Versao));
    if(strcmp(Versao, "0.3.7") && strcmp(Versao, "0.3.7-R3") && strcmp(Versao, "0.3.7-R4"))
    {
        new Dialog[300];
        strcat(Dialog, "\n\t\t{FFFF00}Versão {FF0000}Bloqueada\n");
        strcat(Dialog, "{FFFFFF}Você está usando uma versão antiga do samp\n");
        strcat(Dialog, "{FFFFFF}Versï¿½es liberadas: 0.3.7 ou 0.3.7-R3 ou 0.3.7-R4\n\n");
        strcat(Dialog, "{FFFFFF}Acesse: {00FF00}https://www.sa-mp.com/download.php{FFFFFF} para atualizar seu samp.");
        ShowPlayerDialog(playerid, 1337, DIALOG_STYLE_MSGBOX, "{FF0000}Bloqueado(a)", Dialog, "Fechar", "");
        SetTimerEx("KickEx", 1000, false, "i", playerid);
        return 1;
    }

	if(CaracterEspecial(PegarNick(playerid))){
		SendClientMessage(playerid, 0xFF4500FF, "| SERVIDOR | Seu nick possui caracteres especiais.");
		SetTimerEx("KickEx", 1000, false, "i", playerid);
		return 1;
	}

	if(Whitelist == true)
	{
		new Cache:Conectar,
			Enviar[200],
			Mensagem[128],
			Hwi[50];
		format(Enviar, sizeof(Enviar), "SELECT * FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
		Conectar = mysql_query(IDConexao, Enviar);
		if(mysql_errno(IDConexao) != 0) return Kick(playerid);
		if(cache_num_rows() > 0)
		{
			cache_get_value(0, "Hwid", Hwi, 50);
			cache_delete(Conectar);
			
			// Verificar se eu ainda tenho acaesso
			format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `UsadoPor` = '%s'", EscapeString(PegarNick(playerid)));
			Conectar = mysql_query(IDConexao, Enviar);
			if(mysql_errno(IDConexao) != 0) return Kick(playerid);
			new res;
			if(cache_num_rows() > 0) cache_get_value_name_int(0, "Restante", res);
			cache_delete(Conectar);

			if(res != 0 && res < gettime())
			{
				format(Enviar, sizeof(Enviar), "DELETE FROM `acessocodigo` WHERE `UsadoPor` = '%s'", EscapeString(PegarNick(playerid)));
				mysql_query(IDConexao, Enviar, false);
				format(Enviar, sizeof(Enviar), "DELETE FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
				mysql_query(IDConexao, Enviar, false);
				SendClientMessage(playerid, -1, "| AVISO | Seu acesso expirou");
				SetTimerEx("KickEx", 1000, false, "d", playerid);
				return 1;	
			}

			if(strcmp(Hwi, PegarHWID(playerid)))
			{
				SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu HWID não foi reconhecido!");
				format(Mensagem, sizeof(Mensagem), "[!] Seu HWID:{FF8C00} %s", PegarHWID(playerid));
				SendClientMessage(playerid, -1, Mensagem);
				return  1;
			}
		}
		else
		{
			cache_delete(Conectar);
			format(Mensagem, sizeof(Mensagem), "[!] Seu HWID:{FF8C00} %s", PegarHWID(playerid));
			SendClientMessage(playerid, -1, Mensagem);
			//SetTimerEx("KickEx", 1000, false, "i", playerid);
			LoginCodigo(playerid);
			return 1;
		}
	}

	if(TemInauguracao == false) MostrarLogin(playerid); 
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	if(GetVehicleModel(vehicleid) == 569 || GetVehicleModel(vehicleid) == 481 || GetVehicleModel(vehicleid) == 509 || GetVehicleModel(vehicleid) == 510) SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective); 
	else SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective); 
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(Inauguracao[playerid] == true){
		// if(!AntiFloodMensagem(playerid)){
		// 	return 0;
		// }
		new Mensagem[128];
		format(Mensagem, sizeof(Mensagem), "%s[%d]: %s", PegarNick(playerid), playerid, text);
		SendClientMessageToAll(-1, Mensagem);
		return 0;
	}
	if(Jogador[playerid][Logado] == false) return 0;

	if(Jogador[playerid][EstadoAFK] == true){
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ausente");
		return 0;
	}

	if(Jogador[playerid][Preso] != 0 && Jogador[playerid][CadeiaEstilo] == 0){
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está preso(a) e não pode usar o chat");
		return 0;
	}

	if(Jogador[playerid][Admin] < 1){
		// if(!AntiFloodMensagem(playerid)){
		// 	return 0;
		// }

		if(GetPVarInt(playerid, "EventoJogador") == 2){
			SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode falar no chat");
			return 0;
		}
	}

	if(pAdmin[playerid][Espiando] == true)
	{
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está telando um(a) jogador(a)");
		return 0;
	}

	//if(Jogador[playerid][Preso] != 0){
	//	SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está preso(a)");
	//	return 0;
	//}

	if(strlen(text) > 74){
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Mensagem muito longa");
		return 0;
	} 

	if(Jogador[playerid][Mutado] > gettime()){
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi mutado(a) pela administraï¿½ï¿½o, aguarde.");
		return 0;	
	}

	new Mensagem[200];
	if(GetPVarInt(playerid, "EmLigacao") == 2) 
	{
		new id = GetPVarInt(playerid, "LigacaoID");
		format(Mensagem, sizeof(Mensagem), "| LIGAÇÃO | %s[%d]: %s", PegarNick(playerid), playerid, text);
		SendClientMessage(id, 0x228B22FF, Mensagem);
		SendClientMessage(playerid, 0x228B22FF, Mensagem);

		if(Jogador[id][Admin] == 7 || Jogador[playerid][Admin] == 7) return 0;
		format(Mensagem, sizeof(Mensagem), "| ADMIN-TELEFONE | %s[%d] enviou para %s[%d]: %s", PegarNick(playerid), playerid, PegarNick(id), id, text);
		for(new i=0; i < MAX_PLAYERS; i++)
		{
			if(!IsPlayerConnected(i)) continue;
			if(Jogador[i][Logado] == false) continue;
			if(Jogador[i][Admin] < 2) continue;
			if(pAdmin[i][VerLigacoes] == false) continue;
			SendClientMessage(i, 0x228B22FF, Mensagem);
		}
		return 0;
	}
	
	new TagZZ[20];
	if(Jogador[playerid][BaseID] > 0) strcatEx(TagZZ, "{%06x}[%s]", StrToHex(IntToHex(Base[Jogador[playerid][BaseID]][BaseTagCor])) >>> 8, Base[Jogador[playerid][BaseID]][BaseTag]);

	if(Jogador[playerid][Admin] > 0 && pAdmin[playerid][Camuflado] == false) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[%s{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(1, playerid), GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][Preso] != 0) format(Mensagem, sizeof(Mensagem), "%s{FFFFFF}[{ADFF2F}Cadeia{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", TagZZ, GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][TagPersonalizada] == 1) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{FF0000}YouTuber{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][TagPersonalizada] == 2) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{ad2ec9}Locutor(a){FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][TagPersonalizada] == 4) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{00fa9a}Aguardando{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][TagPersonalizada] == 5) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{9932CC}Streamer{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][TagPersonalizada] == 6) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{FF69B4}Girl{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][BaseID] > 0) format(Mensagem, sizeof(Mensagem), "%s{%06x}%s{FFFFFF}[%d]: %s", TagZZ, GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else if(Jogador[playerid][Vip] > gettime()) format(Mensagem, sizeof(Mensagem), "{FFFFFF}[{%06x}VIP{FFFFFF}] {%06x}%s{FFFFFF}[%d]: %s", StrToHex(IntToHex(Jogador[playerid][CorVIP])) >>> 8, GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	else format(Mensagem, sizeof(Mensagem), "{%06x}%s{FFFFFF}[%d]: %s", GetPlayerColor(playerid) >>> 8, PegarNick(playerid, true), playerid, text);
	ProxDetector(40.0, playerid, Mensagem, -1,-1,-1,-1,-1);
	return 0;
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{	
	// Geral
	if(!strcmp(cmdtext, "/rpnull") && Inauguracao[playerid] == true) return 1;
	if(Jogador[playerid][Logado] == false) return 0;
	if(Jogador[playerid][Admin] < 1)
	{
		// if(!AntiFloodComandos(playerid)){
		// 	return 0;
		// }

		if(GetPVarInt(playerid, "EventoJogador") == 2){
			if(!strcmp(cmdtext, "/relatorio", true)) return 1;
			else if(!strcmp(cmdtext, "/duvida", true)) return 1;
			SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode enviar comandos");
			return 0;
		}

		// Sistema Policial
		if(pAbordado[playerid][Algemado] == true){
			SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está algemado(a)");
			return 0;		
		}
		
		if(pAbordado[playerid][SeRendeu] == true){
			SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está rendido(a)");
			return 0;	
		}

		// Sistema Geral
		if(Jogador[playerid][EstadoAFK] == true){
			SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ausente");
			return 0;
		}
	}

	
	if(pModo[playerid][Jogando] == true && Jogador[playerid][Admin] < 1)
	{
		if(!strcmp(cmdtext, "/desistir", true) && pModo[playerid][ModoAtl] > 0 && pModo[playerid][ModoAtl] != 2) return 1; 
		
		// Arena
		if(!strcmp(cmdtext, "/arenamembros", true) && pModo[playerid][ModoAtl] == 2) return 1; 
		if(!strcmp(cmdtext, "/sairarena", true) && pModo[playerid][ModoAtl] == 2) return 1; 
		if(!strcmp(cmdtext, "/expulsar", true, 9) && pModo[playerid][ModoAtl] == 2) return 1; 

		if(!strcmp(cmdtext, "/relatorio", true, 10) && pModo[playerid][ModoAtl] > 0) return 1;
		if(!strcmp(cmdtext, "/duvida", true, 7) && pModo[playerid][ModoAtl] > 0) return 1;
		SendClientMessage(playerid, 0xFFFF00FF, "| ERRO | Você está jogando e não pode utilizar comandos");
		return 0;
	}

	if(Jogador[playerid][Preso] != 0 && Jogador[playerid][Admin] < 2){
		if(strcmp(cmdtext, "/ficarprisao", true) && strcmp(cmdtext, "/sairprisao", true) && strcmp(cmdtext, "/solicitar", true) && strcmp(cmdtext, "/advogados", true)){
			SendClientMessage(playerid, 0xFFFF00FF, "| ERRO | Você está preso(a) e não pode usar comandos!");
			return 0;
		}
		return 1;
	}
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(!success) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Comando Invï¿½lido.");
	// if(!success) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Comando Inexistente");
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	if(IsPlayerNPC(playerid)) return 1;
    if(Jogador[playerid][Logado] == false) return 0;
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW && Jogador[playerid][AntiEsc] == true){
		SelectTextDraw(playerid, 0xFFA500FF);  
	}
    return 0;
}

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	if(GetPVarInt(playerid, "AntiFloodPick") > gettime()) return 1;
	SetPVarInt(playerid, "AntiFloodPick", gettime()+10);

    new String[200];
    for(new i=0; i < sizeof(Pick); i++)
	{
        if(pickupid == PickupEntrada[i])
		{
            format(String, sizeof(String), "| INFO | Para entrar no(a) %s aperte '{B5B5B5}F{FFFFFF}' ou digite '{B5B5B5}/Entrar{FFFFFF}'", Pick[i][MensagemPickup]);
            SendClientMessage(playerid, -1, String);
            break;
        }
        else if(pickupid == PickupSaida[i])
		{
            format(String, sizeof(String), "| INFO | Para sair do(a) %s aperte '{B5B5B5}F{FFFFFF}' ou digite '{B5B5B5}/Sair{FFFFFF}'", Pick[i][MensagemPickup]);
            SendClientMessage(playerid, -1, String);
            break;
        }
    }
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//Engine do Veículo
	if(newkeys == KEY_YES)
	{
        if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
            new engine, lights, alarm, doors, bonnet, 
			boot, objective, carro = GetPlayerVehicleID(playerid),
			model = GetVehicleModel(carro);
			new cHora, cMinutos, cSegundos;
			gettime(cHora, cMinutos, cSegundos);
            if(model == 481 || model == 509 || model == 510) return 1;
            GetVehicleParamsEx(carro, engine, lights, alarm, doors, bonnet, boot, objective);
            if(engine <= 0)
            {
                if(GetVehicleSpeed(carro) > 6) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está em movimento!");
                if(!VerificarGasolina(carro)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Veículo sem gasolina"); 
				if(cHora >= 16 || cHora <= 5) SetVehicleParamsEx(carro, 1, 1, alarm, doors, bonnet, boot, objective);
                else if(cHora < 16 || cHora > 5) SetVehicleParamsEx(carro, 1, 0, alarm, doors, bonnet, boot, objective);
                SendClientMessage(playerid, 0x32CD32FF, "| INFO | Veículo ligado");
            }
            else
            {
                if(GetVehicleSpeed(carro) > 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está em movimento!");
                SetVehicleParamsEx(carro, 0, 0, alarm, doors, bonnet, boot, objective);
                SendClientMessage(playerid, 0xFE2E2EFF, "| INFO | Veículo desligado");
            }
        }
    }

	//Nitro/Reparo no Click
    if(PRESSED(KEY_FIRE) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
        if(Jogador[playerid][Admin] > 0 || Jogador[playerid][Vip] > gettime()){
        	AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
			if(GetPVarInt(playerid, "ProibidoReparo") == 0 && 
			pAbordado[playerid][Acompanhando] == false && 
			GetPVarInt(playerid, "AntiAbordagem") < gettime() && IsApenasCarro(GetPlayerVehicleID(playerid)) && VeiculoServer[GetPlayerVehicleID(playerid)][VidaMaxima] <= 1000.0) RepairVehicle(GetPlayerVehicleID(playerid));
		}
    }
	return 1;
}