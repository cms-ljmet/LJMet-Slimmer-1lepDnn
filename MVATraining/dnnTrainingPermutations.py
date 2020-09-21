## Python version of runDnnTraing with no manual button pushing 
## corresponds to command < python -u DnnTraining.py outdir arch vararray maxtest testnum >

import os
fileToTrain = 'DnnTrainingBB_VLQanalysis.py'
outdir = 'DnnTrainingBB_Jun2020_BL'          ## Doesn't change
arch = '3x10'   			     ## through 1-5 x10
vararray = 1 				     ## permite through numbers 1 - 6
maxtest = 10000				     ## Permiate through numbers 10000 - 20000 by step [where step == (20000 - 10000) / stepsize
testnum = 0 				     ## increment by one
stepSize = 5
step = 2000

for j in range(2,6):	## For BBTraining, range(2,6), for TTTraining, range(1,6)
	arch = str(j)+'x10'
	for vararray in range(1,7):
		for i in range(1,7):	## defined by step size
			print '---------------------------------------' + '\n' + 'Test Number: '+ str(testnum) + '\n' + 'Arch size: ' + arch + '\n' + 'Var: ' + str(vararray) + '\n' + 'Max number of tests: ' + str(maxtest)  + '\n' + 'Output Directory: ' + outdir + '\n' + '---------------------------------------'
			os.system('python -u '+ fileToTrain+ ' '+ outdir+ ' '+ arch+' '+ str(vararray)+ ' '+ str(maxtest)+ ' '+ str(testnum))
                	testnum = testnum + 1
			if maxtest >= 20000:
				maxtest = 10000
			else:
				maxtest = maxtest + step

## In case of issues, this can be used to modify the amount of permutations and start from the middle
			#else:
			#	print '---------------------------------------' + '\n' + 'Test Number: '+ str(testnum) + '\n' + 'Arch size: ' + arch + '\n' + 'Var: ' + str(vararray) + '\n' + 'Max number of tests: ' + str(maxtest)  + '\n' + 'Output Directory: ' +  outdir + '\n' + '---------------------------------------' + '\n' + 'ALREADY RAN, NO RERUN PER USER INSTRUCTION'
			#testnum = testnum + 1
                        #if maxtest >= 20000:
                        #        maxtest = 10000
                        #else:
                        #        maxtest = maxtest + step

