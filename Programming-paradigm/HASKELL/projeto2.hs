-- Trabalho realizado por
-- Fabio Moreira
-- João Pedro Bresolin Ortigara
-- Ricardo do Nascimento Boing

module SerieFinInf (somaInteiros,somaIntImpares,somaQuadInteiros,
							somaQuadInteirosImpares,quaseUm, quaseDois, quaseE) where

-- Soma dos n primeiros inteiros

preSoma :: Float  -> Float 
preSoma x = (x*(x+1)/2)

somaInt :: Float -> [Float]
somaInt n = map preSoma [1..n]

somaInteiros :: Float -> Float
somaInteiros n = last (somaInt n)

-- --------------------------------
-- Soma dos n primeiros inteiros ímpares

somaImp :: Float -> [Float]
somaImp n = map preSoma [1,3..n]

somaIntImpares :: Float -> Float
somaIntImpares n = last (somaImp n) - sum [2,4..n-1]

-- -----------------------------------
-- Soma dos Quadrados dos inteiros

preQuad :: Float -> Float
preQuad n = (n*(n+1)*(2*n+1))/ 6

somaQuad :: Float -> [Float]
somaQuad n = map preQuad [1..n]

somaQuadInteiros :: Float -> Float
somaQuadInteiros n = last (somaQuad n)

-- --------------------------------------
-- Soma Quadrados dos inteiros ímpares

somaQuadInteirosImpares n  = last (somaQuad n) - sum (map (**2) [2,4..n-1])
-----------------------------------------
-- Parte II

factorial :: Float -> Float
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- QuaseUm 
quaseUm :: Int -> Float
quaseUm n = sum (map (\x->(1/(x^2+x))) (take n [1..]))

-- QuaseDois
quaseDois :: Int -> Float
quaseDois n = sum (map (\x->(2/(x^2+x))) (take n [1..]))

-- QuaseE
quaseE :: Int -> Float
quaseE n = 1+(sum (map (\x->((1/(factorial x)))) (take n [1..])))
