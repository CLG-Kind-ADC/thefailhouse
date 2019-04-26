import numpy as np
from kmodes.kmodes import KModes
from kmodes.kprototypes import KPrototypes
import matplotlib.pyplot as plt
from matplotlib import style

np.random.seed(100)

style.use("ggplot")

# medium article includes a colors setting
# won't use unless I have to

soybeans = np.genfromtxt('soybean_small.txt',dtype=str, delimiter=',')

soybeans_true = soybeans[:,35]
soybeans_attrs = soybeans[:,0:34]

# at this point, I'm hardcoding 4 clusters because I know there are 4 clusters.
# there must be - are - ways to do this through (no doubt) CV, the "elbow method"
kmo = KModes(n_clusters = 4, init = 'Huang', n_init = 5, verbose = 1)
clusters = kmo.fit_predict(soybeans_attrs)

# Print cluster centroids of the trained model.
print(kmo.cluster_centroids_)
# Print training statistics
print(kmo.cost_)
print(kmo.n_iter_)
# gee golly I hope that worked.

for s, c in zip(soybeans_true, clusters):
    print("Result: {}, cluster:{}".format(s, c))
    # I don't know what (zip) is,
    # but my guess would be something that zips the two things together

# plots?

# "Plot the results"
for i in set(kmo.labels_): # okay, I don't know `set` either
    index = kmo.labels_ == i
    plt.plot(soybeans_attrs[index, 0], soybeans_attrs[index, 1], 'o')
    plt.suptitle('Data points categorized by category score', fontsize=18)
    plt.xlabel('Category Score', fontsize=16)
    plt.ylabel('Category Type', fontsize=16)
plt.show()
# okay. SOMETHING happened. I'm not exactly sure what I'm looking at.

# Clustered result
fig1, ax3 = plt.subplots()
scatter = ax3.scatter(soybeans_true, clusters, c=clusters, s=50)
ax3.set_xlabel('Data points')
ax3.set_ylabel('Cluster')
plt.colorbar(scatter)
ax3.set_title('Data points classifed according to known centers')
plt.show()

result = zip(soybeans_true, kmo.labels_)
sortedR = sorted(result, key=lambda x: x[1])
print(sortedR)


# now, trying to implement an elbow method of cross validation
# instead of just popping an n_clusters hardcode in.

within_cluster_sim = []
for i in range(1,16):
	km_o = KModes(n_clusters = i, init='Huang',n_init=5,verbose=1) # deliberately excluded the n_init param, at least at first
	# n_init: "number of times the k-modes algo will be run with different centroid seeds." Default 10.
	km_o.fit_predict(soybeans_attrs) # oh, that's a hard code. GG.
	within_cluster_sim.append(km_o.cost_)

K = range(1,16)
plt.plot(K, within_cluster_sim, 'bx-')
plt.xlabel('k')
plt.ylabel('similarity?')
plt.title('elbow method??')
plt.show()
# there is randomness here. christ. ought to set a seed...how

# another addition
# I spent a while needlessly constructing a problem for myself
n_clusters_drops = []
for i in range(1,15):
	n_clusters_drops.append(within_cluster_sim[i] - within_cluster_sim[i-1])

# hmm. much to ponder.


# having a go at kprototypes now
# first attempted to clean through R (refer to `techniques_sandbox.R`)
# but that gave me SO damn much trouble.
cleaned_cc_approv = np.genfromtxt('cleaned_credit_approval.csv',dtype=str, delimiter=',')
cleaned_cc_approv = cleaned_cc_approv[1:,:]
# christ.
# coercion issues are KILLING me, most likely because of the goddamn way R writes csvs.
# my hack: used R to write a text file with the indices to remove...
# bad, bad phoebe.
indices = np.genfromtxt('exclude_these.txt')
indices = list(indices.astype(int))

cleaned_cc_approv = np.genfromtxt('credit_approval.txt',dtype=str,delimiter=',')
# cleaned_cc_approv = cleaned_cc_approv[1:,:] # don't need this line anymore because not dealing with the R-written file!!
cleaned_cc_approv = np.delete(cleaned_cc_approv,indices,0)


#####

# eventually...(uncomment all below this line)

cleaned_cc_approv1 = cleaned_cc_approv[:,15]
cleaned_cc_approv2 = cleaned_cc_approv[:,0:14]

within_cluster_sim_proto = []
for i in range(1,16):
	kp_o = KPrototypes(n_clusters = i, init='Cao',n_init=5,verbose=1) # deliberately excluded the n_init param, at least at first
	# n_init: "number of times the k-modes algo will be run with different centroid seeds." Default 10.
	kp_o.fit_predict(cleaned_cc_approv2,categorical=[0,3,4,5,6,8,9,11,12]) # oh, that's a hard code. GG.
	within_cluster_sim_proto.append(kp_o.cost_)

K = range(1,16)
plt.plot(K, within_cluster_sim_proto, 'bx-')
plt.xlabel('k')
plt.ylabel('proto similarity?')
plt.title('proto elbow method??')
plt.show()

# damn, I would have chosen like, 4...
# need to figure out how to set seeds in python

kpo2 = KPrototypes(n_clusters = 2, init = 'Cao', n_init = 5, verbose = 1) # could try init='Huang' on kproto sometime maybe
clusters2 = kpo2.fit_predict(cleaned_cc_approv2,categorical=[0,3,4,5,6,8,9,11,12])

# Print cluster centroids of the trained model.
print(kpo2.cluster_centroids_)
# Print training statistics
print(kpo2.cost_)
print(kpo2.n_iter_)
# gee golly I hope that worked.

for s, c in zip(cleaned_cc_approv1, clusters2):
    print("Result: {}, cluster:{}".format(s, c))
    # still don't know what zip is, yeah that hasn't changed



kpo4 = KPrototypes(n_clusters = 4, init = 'Cao', n_init = 5, verbose = 1)
clusters4 = kpo4.fit_predict(cleaned_cc_approv2,categorical=[0,3,4,5,6,8,9,11,12])

# Print cluster centroids of the trained model.
print(kpo4.cluster_centroids_)
# Print training statistics
print(kpo4.cost_)
print(kpo4.n_iter_)
# gee golly I hope that worked.

for s, c in zip(cleaned_cc_approv1, clusters4):
    print("Result: {}, cluster:{}".format(s, c))

# 

