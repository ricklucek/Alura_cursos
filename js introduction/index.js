import {cliente} from "./Cliente.js";
import {contaCorrente} from "./ContaCorrente.js";
import { contaPoupanca } from "./contaPoupaca.js";

const cliente1 = new cliente("Ricardo",11122233309);
const contaCorrenteRicardo = new contaCorrente(1001, cliente1);
contaCorrenteRicardo.depositar(500);
contaCorrenteRicardo.sacar(100);

const contaPoupanca = new contaPoupanca(50,cliente1,1001);

console.log(contaCorrenteRicardo)