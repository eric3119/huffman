library(ggplot2)

 ggplot(data=banco) +
 geom_point(aes(x = numero_sorteado, y = lista), color= 'red') +
 geom_point(aes(x = numero_sorteado, y = abb), color='blue')+
 xlab("Numero sorteado") +
 ylab("Numero de Comparacoes") +
ggtitle("ABB X Lista")
