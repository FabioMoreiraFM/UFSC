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
Feature: Calcular Média do Percentual Incorporado por Cargo

  @tag1
  Scenario: Calculo media do percentual incorporado por cargo
    Given cargo eh "Diretor"
    	And ativo eh "true"
    When calcula a media do percentual incorporado por cargo
    Then O sistema soma os percentuais de todos os registros ativos de VPNI
    	And divide pelo numero de registros encontrados resultando na media