import {cliente} from "./Cliente.js";
import {contaCorrente} from "./ContaCorrente.js";
import { contaPoupanca } from "./contaPoupaca.js";
import {conta} from "./conta.js"

const cliente1 = new cliente("Ricardo",11122233309);

const contaCorrenteRicardo = new contaCorrente(cliente1, 1001);
contaCorrenteRicardo.depositar(500);
contaCorrenteRicardo.sacar(100);

const contaPoup = new contaPoupanca(50, cliente1, 1001);
console.log(contaPoup);
console.log(contaCorrenteRicardo);