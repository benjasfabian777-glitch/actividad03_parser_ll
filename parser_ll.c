
/*
 * Matricula: 10240036
 * Nombre completo: BENJAMIN FABIAN GABINO
 * Actividad 3: gramatica de expresiones y analizador descendente LL
 */

#include <stdio.h>
#include <stddef.h>

/* Microetapa A: categorias disponibles en la entrada. */
typedef enum {
    TOK_ID, TOK_NUM, TOK_MAS, TOK_MENOS, TOK_POR, TOK_DIV,
    TOK_PAR_IZQ, TOK_PAR_DER, TOK_FIN, TOK_OTRO
} TipoToken;

/* Microetapa B: un token combina categoria y lexema. */
typedef struct {
    TipoToken tipo;
    const char *lexema;
} Token;

/* Microetapa C: Parser conserva entrada, limite y cursor. */
typedef struct {
    const Token *tokens;
    size_t cantidad;
    size_t posicion;
    int mostrar_traza;
} Parser;

/* Microetapa D: CasoPrueba agrega nombre y resultado esperado. */
typedef struct {
    const char *nombre;
    const Token *tokens;
    size_t cantidad;
    int esperado;
    int mostrar_traza;
} CasoPrueba;

const char *nombre_token(TipoToken tipo)
{
    switch (tipo) {
        case TOK_ID: return "ID";
        case TOK_NUM: return "NUM";
        case TOK_MAS: return "MAS";
        case TOK_MENOS: return "MENOS";
        case TOK_POR: return "POR";
        case TOK_DIV: return "DIV";
        case TOK_PAR_IZQ: return "PAR_IZQ";
        case TOK_PAR_DER: return "PAR_DER";
        case TOK_FIN: return "FIN";
        case TOK_OTRO: return "OTRO";
    }
    return "DESCONOCIDO";
}

const Token *token_actual(const Parser *p)
{
    if (p->posicion >= p->cantidad) {
        return NULL;
    }
    return &p->tokens[p->posicion];
}

void trazar(const Parser *p, const char *regla)
{
    const Token *t;
    if (!p->mostrar_traza) {
        return;
    }
    t = token_actual(p);
    if (t == NULL) {
        printf("  [pos=%zu, sin token] %s\n", p->posicion, regla);
        return;
    }
    printf("  [pos=%zu, lookahead=%s \"%s\"] %s\n",
           p->posicion, nombre_token(t->tipo), t->lexema, regla);
}

int consumir(Parser *p, TipoToken esperado)
{
    const Token *t = token_actual(p);
    if (t == NULL) {
        printf("  [ERROR sintactico] Se esperaba %s, pero no quedan tokens.\n",
               nombre_token(esperado));
        return 0;
    }
    if (t->tipo != esperado) {
        printf("  [ERROR sintactico] Se esperaba %s y se encontro %s \"%s\" en pos=%zu.\n",
               nombre_token(esperado), nombre_token(t->tipo),
               t->lexema, p->posicion);
        return 0;
    }
    if (p->mostrar_traza) {
        printf("  [consume] %s \"%s\"\n", nombre_token(t->tipo), t->lexema);
    }
    p->posicion++;
    return 1;
}



/* Microetapa E: comprobar que los tipos ya forman un programa valido. */
int main(void)
{
    puts("CHECKPOINT 1: estructuras listas.");
    return 0;
}
