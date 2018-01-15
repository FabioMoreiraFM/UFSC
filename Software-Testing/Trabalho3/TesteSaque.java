package testes;

import static org.hamcrest.MatcherAssert.*;
import static org.hamcrest.core.IsEqual.*;
import static org.junit.Assert.assertEquals;

//import static org.junit.Assert.*;
import org.junit.*;
import br.ufsc.ine.leb.projetos.estoria.*;
import br.ufsc.ine.leb.sistemaBancario.*;


@FixtureSetup(TesteConta.class)

public class TesteSaque {	
	@Fixture Conta maria;
	@Fixture SistemaBancario sisbb;
	
	private Operacao operacao;
	
	@Before
	public void setupDeposito() {
		Dinheiro quatroReais = new Dinheiro(Moeda.BRL, 4,0);
		operacao = sisbb.depositar(maria, quatroReais);
	}
	
	@Test
	public void realizaSaqueComSucesso() {
		operacao = sisbb.sacar(maria, new Dinheiro(Moeda.BRL, 6, 0));
		assertEquals(EstadosDeOperacao.SALDO_INSUFICIENTE,operacao.obterEstado().SALDO_INSUFICIENTE);
		assertEquals(new Dinheiro(Moeda.BRL, 4,0), maria.calcularSaldo().obterQuantia());
	}
	
	@Test
	public void realizaSaqueComSucessoHamcrest() {
		operacao = sisbb.sacar(maria, new Dinheiro(Moeda.BRL, 6, 0));
		assertThat(EstadosDeOperacao.SALDO_INSUFICIENTE, equalTo(operacao.obterEstado().SALDO_INSUFICIENTE));
		assertThat(new Dinheiro(Moeda.BRL, 4,0), equalTo(maria.calcularSaldo().obterQuantia()));
	}
}
