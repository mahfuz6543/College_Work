download.file("http://www.openintro.org/stat/data/bdims.RData", destfile = "bdims.RData")
load("bdims.RData")
head(bdims)

mdims = subset(bdims, bdims$sex == 1)
fdims = subset(bdims, bdims$sex == 0)

fdims$hgt
mdims$hgt

hist(fdims$hgt)
hist(mdims$hgt)

#Exercise1
fhgtmean = mean(fdims$hgt)
fhgtsd = sd(fdims$hgt)

hist(fdims$hgt, probability = TRUE , ylim = c(0, 0.06))
x = 140:190
y = dnorm(x = x, mean = fhgtmean, sd = fhgtsd)
lines(x = x, y = y, col = "blue")

#Exercise2
qqnorm(fdims$hgt)
qqline(fdims$hgt)

sim = rnorm(n = length(fdims$hgt), mean = fhgtmean, sd = fhgtsd)
hist(sim)
qqnorm(sim)
qqline(sim)

#Exercise3
qqnormsim(fdims$hgt)

#Exercise5
fdims$wgt
mdims$wgt

hist(fdims$wgt)
hist(mdims$wgt)

1 - pnorm(q = 182, mean = fhgtmean, sd = fhgtsd)
sum(fdims$hgt > 182)/length(fdims$hgt)

#Exercise6
fdims$bii.di
hist(fdims$bii.di)
qqnorm(fdims$bii.di)
qqline(fdims$bii.di)

fdims$elb.di
hist(fdims$elb.di)
qqnorm(fdims$elb.di)
qqline(fdims$elb.di)

bdims$age
hist(bdims$age)
qqnorm(bdims$age)
qqline(bdims$age)

fdims$che.de
hist(fdims$che.de)
qqnorm(fdims$che.de)
qqline(fdims$che.de)

#Exercise8
fdims$kne.di
hist(fdims$kne.di)
qqnorm(fdims$kne.di)
qqline(fdims$kne.di)