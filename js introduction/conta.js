export class conta{
    constructor(saldoInicial, cliente, agencia){
        this._saldo = saldoInicial;
        this._cliente = cliente;
        this._agencia = agencia;
    }

    set cliente(novoValor){
        if (novoValor instanceof cliente){

            this._cliente = novoValor;
        };
    };

    get cliente(){
        return this._cliente;
    }

    sacar(valor){
        let taxa = 1
        return this._sacar(valor, taxa);
        }

    _sacar(valor, taxa){
        const valorSacado = taxa * valor;
        if (this._saldo > valorSacado){
            this._saldo -= valorSacado;
            return valorSacado;
        }

        return 0;
    }

    depositar(valor){
        if (valor > 0){
            this._saldo += valor
            return valor
        }
    }

    tranferir(valor, conta){
        const valorSacado = this.sacar(valor);
        conta.depositar(valorSacado);
    }
}