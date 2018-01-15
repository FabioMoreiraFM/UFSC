function M = fMultiplicidade(R)
    % Nº de restos próximos de zero (< Rlimite)
    Rlimite = 1e-4; % Pode otimizar aqui, diminui nº de passos, pode-se usar 0.1 por exemplo
    M = 1;
    soma = abs(R(1)) + abs(R(2));
    while soma < Rlimite
        M++;
        soma += abs(R(M+1));
    end
end