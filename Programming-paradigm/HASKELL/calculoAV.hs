-- Trabalho Realizado por
-- Fabio Moreira 
-- João Pedro Bresolin Ortigara 
-- Ricardo do Nascimento Boing 

module CalculoAV ( alcilindro, atcilindro, volumeCilindro,
		   alTroncoCone, atTroncoCone, volumeTroncoCone,
		   areaEsferoideProlato, volumeEsferoideProlato,
           aEsfera, vEsfera, alCone, atCone, vCone,
           aEsferoideOblato, vEsferoideOblato) where

-- Cilindro

alcilindro :: Float -> Float -> Float
alcilindro r h  = 2*pi*r*h

atcilindro :: Float -> Float -> Float
atcilindro r h = (alcilindro r h) + 2*pi*(r**2)

volumeCilindro :: Float -> Float -> Float
volumeCilindro r h = pi*(r**2)*h

-- Tronco de cone

alTroncoCone :: Float -> Float -> Float -> Float
alTroncoCone r1 r2 h = pi*(r1+r2)*sqrt( (h**2) + ( (r1+r2)**2))

atTroncoCone :: Float -> Float -> Float -> Float
atTroncoCone r1 r2 h = pi*(r1**2) + pi*(r2**2) + (alTroncoCone r1 r2 h)

volumeTroncoCone :: Float -> Float -> Float -> Float
volumeTroncoCone r1 r2 h = (1/3) * (pi*h*( r1**2 + r2**2 + r1*r2))

-- Esferoide Prolato

areaEsferoideProlato :: Float -> Float -> Float
areaEsferoideProlato a b = 2*pi*(b**2) + 2*pi*(a*b/ (e a b))*asin (e a b)

volumeEsferoideProlato :: Float -> Float -> Float
volumeEsferoideProlato a b = (4/3)*pi*a*b**2

e :: Float -> Float -> Float
e a b = sqrt(a**2 + b**2) / a

-- Esfera

aEsfera :: Float -> Float
aEsfera r = 4 * pi * (r**2)

vEsfera :: Float -> Float
vEsfera r = (4/3) * pi * (r**3)

-- Cone

alCone :: Float -> Float -> Float
alCone r h = pi * r * sqrt(r**2 + h**2)

atCone :: Float -> Float -> Float
atCone r h = pi * r * (sqrt(r**2 + h**2) + r)

vCone :: Float -> Float -> Float
vCone r h = (1/3) * pi * r**2 * h

-- Esferoide oblato

aEsferoideOblato :: Float -> Float -> Float
aEsferoideOblato a b = (2 * pi * a**2) + (b**2/(e a b)) *(log (1 + (e a b))/(1 - (e a b)))

vEsferoideOblato :: Float -> Float -> Float
vEsferoideOblato a b = (4/3) * pi * a**2 * b
