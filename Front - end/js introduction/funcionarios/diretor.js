import { funcionario } from "./funcionario.js";

export class diretor extends funcionario{
    constructor(nome, salario, cpf) {
        super(nome, salario, cpf);
        this._bonificacao = 1.2;
    }
}