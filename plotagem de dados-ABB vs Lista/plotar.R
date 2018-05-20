library(ggplot2)
Plotar Lista
 ggplot(data=banco, aes(x=numero_sorteado, y=lista)) +
 theme(legend.title=element_blank()) +
 geom_point(color='orange') +
 xlab("Numero sorteado") +
 ylab("Comparacoes na Lista") +
ggtitle("Grafico da Lista")

Plotar ABB
 ggplot(data=banco, aes(x=numero_sorteado, y=abb)) +
 theme(legend.title=element_blank()) +
 geom_point(color='orange') +
 xlab("Numero sorteado") +
 ylab("Comparacoes na ABB") +
ggtitle("Grafico da ABB")