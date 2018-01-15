package testes;

import static org.junit.Assert.*;

import org.junit.*;

import br.ufsc.ine.leb.projetos.estoria.*;
import br.ufsc.ine.leb.sistemaBancario.*;

@FixtureSetup(TesteAgencia.class)
public class TesteConta {
	@Fixture Agencia centro;
	@Fixture SistemaBancario sisbb;
	
	private Conta maria;
	
	@Before
	public void setupConta() {
		maria = centro.criarConta("Maria");
	}
	
	@Test
	public void criacaoBemSucedidaConta() {
		assertEquals("Maria", maria.obterTitular());
		assertEquals(centro, maria.obterAgencia());
		assertEquals("0001-5", maria.obterIdentificador());
		assertTrue(maria.calcularSaldo().zero());
	}
	
}
