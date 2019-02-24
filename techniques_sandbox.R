######## library read-ins

# ridge and lasso regression
library(glmnet)

# trees and forests and their ilk
library(tree)
library(rpart)
library(rpart.plot)
library(randomForest)
library(fastAdaboost)

# linear model selection
library(leaps)

# Our data library
library(ISLR)

data("Hitters")
Hitters = na.omit(Hitters)

# first, some warmup: run simple subset selection
a_reg <- regsubsets(Salary ~ ., data = Hitters, method="exhaustive", nvmax = 19)

plot(a_reg,scale="bic")
plot(a_reg, scale = "Cp")
plot(a_reg, scale="r2")
plot(a_reg,scale="adjr2")

which.min(summary(a_reg)$bic) # also an interesting function I didn't remember.
which.max(summary(a_reg)$adjr2) # :O !

# cross validation of this
## as we 'remember' from grad school, one of the big goals of CV is to better understand our expected test error.

set.seed(1)
train = sample(c(TRUE,FALSE), nrow(Hitters),replace = T) # this is like actually fucking snazzy code
# but it's probably a straight Bernoulli p=0.5...if you want your split to be 20/80 this wouldn't fly as is
test = !train
regfit.best = regsubsets(Salary ~ . , data = Hitters[train,],nvmax = 19)
# honestly, I don't know why they do model.matrix for the test set but not for the training set
# oh, now I kind of have some ideas why.
test.mat = model.matrix(Salary~.,data=Hitters[test,])
# because we're sandboxing, I wanted to compare test.mat to the non-model matrix'd thing
head(test.mat); head(Hitters[test,])
# test.mat has an Intercept, and it doesn't have the Salary variable.

# they next run a function to make predictions for the test observations and assess its error
val.errors = NULL
# oh boy, I get to write a for loop
for(i in 1:19){
  coefi = coef(regfit.best, id = i) # didn't know id was a possible parameter...hm
  # actually, didn't know we could do this^ at all. neat
  pred = test.mat[,names(coefi)] %*% coefi # mat mult
  val.errors[i] = mean((Hitters$Salary[test]-pred)^2)
}
val.errors
which.min(val.errors) # the "least-wrong" (?) prediction came from the 10-variable model
coef(regfit.best,10)

predict.regsubsets = function(object, newdata, id, ...){
  form = as.formula(object$call[[2]]) # specifically extracts "Salary ~ ." and formularizes it and that's it
  mat = model.matrix(form,newdata)
  coefi=coef(object,id=id)
  xvars = names(coefi)
  return(mat[,xvars] %*% coefi)
# no return in the book? would that change anything?
}

# let's turn this into a GAM sandbox, or a general sandbox, too, why don't we
library(gam)
library(splines)
library(akima)

data(Wage)
YaleToolkit::whatis(Wage)

data("kyphosis")


# any playing with prophet?
library(prophet)


# thinking about data sets to use for clustering
sb_small = read.csv("~/OneDrive - RAPP/test_repo_holder/AAA-Sandbox-Phoebe/other_things/soybean_small.txt",header=F)
YaleToolkit::whatis(sb_small)
# hhmmm...
# maybe some of those numbers are actually categorical factors.
# read the note in the paper. ALL of those numbers are supposed to be categorical factors.

#tests for the python script
cred_approv=read.csv("~/OneDrive - RAPP/test_repo_holder/AAA-Sandbox-Phoebe/other_things/credit_approval.txt",header=F)
YaleToolkit::whatis(cred_approv)
# no missing vals after all?
# damn, no. the ones that are, are given as "?"
# this shit again
# ugh
q_marks = which(apply(cred_approv, MARGIN = 1, FUN = function(x){return(sum(grepl("\\?",x)))})>0)
cred_approv = cred_approv[-q_marks,]
# gives me 653 obs instead of the promised 666 from Huang
write.table(cred_approv,"cleaned_credit_approval.txt",row.names = F,sep=",")
YaleToolkit::whatis(cred_approv)

write((q_marks-1),"~/OneDrive - RAPP/test_repo_holder/AAA-Sandbox-Phoebe/other_things/exclude_these.txt",ncolumns = 1)
