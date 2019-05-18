n = 1000

coin1 = c("head","head")
coin2 = c("head","tail")

flip_coin = function(coin){
	s = sample( 1:2, 1)
	return(coin[s])
}

m = 1000
hist_this = NULL

for(j in 1:m){
table_this = NULL
for ( i in 1:n){
	s2 = sample( 1:2, 1)
	if(s2 == 1){coin_x <- coin1} else { coin_x <- coin2 }
	table_this[i] = flip_coin(coin_x)
} 
hist_this[j] = length(table_this[which(table_this == "tail")]) / n
}

table(table_this)
barplot(table(table_this),main="Results of flipping (1 trial)")
hist(hist_this,main = "Distribution of Tails over 1000 repetitions of 1000 flips",xlab="empirical proportion")
