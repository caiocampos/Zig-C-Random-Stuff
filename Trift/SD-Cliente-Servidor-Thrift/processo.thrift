namespace java   processo
namespace csharp processo

struct Resultado {
	1: bool   sinal,
	2: string mensagem,
}

service ProcessoServidor {
	Resultado armazenar(1: string nome, 2: string telefone),
	Resultado atualizar(1: string nome, 2: string telefone),
	Resultado remover  (1: string nome),
	Resultado recuperar(1: string nome)
}