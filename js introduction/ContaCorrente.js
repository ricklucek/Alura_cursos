import {cliente} from "./Cliente.js";
export class contaCorrente {
    static numeroDeContas = 0;

    set cliente(novoValor){
        if (novoValor instanceof cliente){

            this._cliente = novoValor;
        };
    };

    get cliente(){
        return this._cliente;
    }

    constructor(agencia, cliente){
        this.agencia = agencia;
        this.cliente = cliente;
        this._saldo = 0;
        contaCorrente.numeroDeContas += 1;
    }

    sacar(valor){
        if (this._saldo > valor){
            this._saldo -= valor
            return valor
        }
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
