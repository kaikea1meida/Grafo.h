/* 
passo a passo

ve se o grafo é null ou se tem 0 vertices

faz um loop e deixa 

    g->[i].japassou = 0;
    chamar eep ( que devolve 1 e 0)
    ver se eep devolveu 0 ( se eep devolveu 0 pra n-1 vertices acaba e não é cordal pq n tem como ter só um simplicial)
    chamar esse eep até acabar os vertices ou ter n-1 falhas retonra 0

    se um resultado for bem sucedido retorna 1, É cordal.


    

*/