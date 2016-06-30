happyfunction=function(n){
  
    if(n<=2){
      
n= 1
}
    else
      n = happyfunction(n-1) + happyfunction(n-2)
}