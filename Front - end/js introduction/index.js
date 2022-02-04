import {cliente} from "./Cliente.js";
import { gerente } from "./funcionarios/gerente.js";
import { diretor } from "./funcionarios/diretor.js";
import { sistemaAutenticacao } from "./sistemaAutenticacao.js";

const odiretor = new diretor("Rodrigo", 10000, 12345678900);
const ogerente = new gerente("Ricardo", 5000, 12345678901);
ogerente.cadastrarSenha("123456");

const estaLogado = sistemaAutenticacao.login(gerente, "123456");

console.log(estaLogado);