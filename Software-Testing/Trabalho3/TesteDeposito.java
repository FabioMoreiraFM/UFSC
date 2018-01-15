package testes;

import static org.junit.Assert.*;
import org.junit.*;
import br.ufsc.ine.leb.projetos.estoria.*;
import br.ufsc.ine.leb.sistemaBancario.*;

@FixtureSetup({TesteConta.class, TesteDinheiro.class})
public class TesteDeposito {	
	@Fixture Conta maria;
	@Fixture Dinheiro dezReais;
	@Fixture SistemaBancario sisbb;
	
	private Operacao operacao;
	
	@Test
	public void operacaoRealizadaSucesso() {
		operacao = sisbb.depositar(maria, dezReais);
		assertEquals(EstadosDeOperacao.SUCESSO,operacao.obterEstado().SUCESSO);
		assertEquals(maria.calcularSaldo().obterQuantia(), dezReais);
	}
}
