#define    MAX_POSTES   (2300)

enum PostesInfo
{
    bool:PosteColocado,
    PosteModelo,
    PosteID,
    Float:PosteX,
    Float:PosteY,
    Float:PosteZ,
    Float:PosteRX,
    Float:PosteRY,
    Float:PosteRZ
};

new Poste[MAX_POSTES][PostesInfo];