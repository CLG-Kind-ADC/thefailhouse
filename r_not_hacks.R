## 45-degree angle for boxplots code from stackoverflow
x <- barplot(table(mtcars$cyl), xaxt="n")
labs <- paste(names(table(mtcars$cyl)), "cylinders")
text(cex=1, x=x-.25, y=-1.25, labs, xpd=TRUE, srt=45)

## class of each row in a data frame
sapply(iris,class) # I think I'd been using apply, which sucked for the purpose


## a possible mode function
Mode <- function(x, na.rm = FALSE) {
  if(na.rm){
    x = x[!is.na(x)]
  }
  
  ux <- unique(x)
  return(ux[which.max(tabulate(match(x, ux)))])
}

## coerce all characters to factor
iris2 <- as.data.frame(lapply(iris, function(x) {if (is.factor(x)) {as.character(x)}
                               else {x}
                               }) )
