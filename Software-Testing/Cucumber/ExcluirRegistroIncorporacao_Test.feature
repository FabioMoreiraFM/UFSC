#Author: your.email@your.domain.com
#Keywords Summary :
#Feature: List of scenarios.
#Scenario: Business rule through list of steps with arguments.
#Given: Some precondition step
#When: Some key actions
#Then: To observe outcomes or validation
#And,But: To enumerate more Given,When,Then steps
#Scenario Outline: List of steps for data-driven as an Examples and <placeholder>
#Examples: Container for s table
#Background: List of steps run before each of the scenarios
#""" (Doc Strings)
#| (Data Tables)
#@ (Tags/Labels):To group Scenarios
#<> (placeholder)
#""
## (Comments)
#Sample Feature Definition Template
@tag
Feature: Excluir registro de Incorporacao (VPNI)
  Exclusao de registros baseado nas 3 regras da Task I

  @tag1
  Scenario: Exclusao registro sem antecedentes
  Given tipoVPNI eh "10"
    And ativo eh "true"
  When O usuario nao possui registros anteriores
  Then O sistema deve excluir o usuario com sucesso
        

  @tag2
  Scenario: Exclusao registro com antecedentes e retificacao false
  Given ativo eh "true"
  	And flagRetificacao eh "false"
  When Excluir registro atual
  Then Procurar registro antigo com valor TipoRegistro = TipoDoRegistroAtual-10
  	And procurar dentre esses registros retificacao=null
  	And altere o atributo Ativo para true
  	And remover registro atual

  @tag3
  Scenario: Exclusao registro com antecedentes e retificacao true
  Given ativo eh "true"
  	And flagRetificacao eh "true"
  When Excluir o registro atual
  Then Procure registro antigo com mesmo TipoVPNI do registro atual
  	And que possua referencia para o registro atual
  	And altere o campo Ativo para true
  	And o campo retificacao para null
  