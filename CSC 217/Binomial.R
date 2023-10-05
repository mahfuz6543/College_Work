#Excercise1
rbinom(100,10,0.3)

#Excercise2&3
flips <- rbinom(10000,10,0.3)
mean(flips == 2)
dbinom(2,10,0.3)


flips <- rbinom(100000000,10,0.3)
mean(flips == 2)
dbinom(2,10,0.3)

#Excercise4&5
mean(flips <- rbinom(100000000,25,0.3))

var(rbinom(100000000,25,0.3))