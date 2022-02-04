export class sistemaAutenticacao{
    static login(funcionario, senha){
        return funcionario.senha == senha;
    }
}