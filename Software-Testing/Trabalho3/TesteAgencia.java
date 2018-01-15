package testes;

import static org.hamcrest.MatcherAssert.*;
import static org.hamcrest.core.IsEqual.*;
import static org.junit.Assert.assertEquals;

import org.junit.*;

import br.ufsc.ine.leb.projetos.estoria.*;
import br.ufsc.ine.leb.sistemaBancario.*;

@FixtureSetup(TesteBancario.class)
public class TesteAgencia {
	@Fixture private Banco bb;
	@Fixture SistemaBancario sisbb;
	
	private Agencia centro;
	
	@Before
	public void setupAgencia() {
		centro = bb.criarAgencia("Centro");
	}
	
	@Test
	public void criacaoBemSucedidaAgencia() {
		assertEquals("001", centro.obterIdentificador());
		assertEquals("Centro", centro.obterNome());
		assertEquals(bb, centro.obterBanco());
	}
	
	@Test
	public void criacaoBemSucedidaAgenciaHamcrest() {
		assertThat("001", equalTo(centro.obterIdentificador()));
		assertThat("Centro", equalTo(centro.obterNome()));
		assertThat(bb, equalTo(centro.obterBanco()));
	}
	
}
