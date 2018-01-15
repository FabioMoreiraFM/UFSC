package testes;

import static org.junit.Assert.*;

import org.junit.*;

import br.ufsc.ine.leb.sistemaBancario.*;

public class TesteBancario {
	private Banco bb;
	private SistemaBancario sisbb;
	
	@Before
	public void setupBanco() {
		sisbb = new SistemaBancario();
		bb = sisbb.criarBanco("Banco do Brasil", Moeda.BRL);
	}
	
	@Test
	public void criacaoBemSucedidaBanco() {
		assertEquals("Banco do Brasil", bb.obterNome());
		assertEquals(Moeda.BRL, bb.obterMoeda());
	}
	
}
