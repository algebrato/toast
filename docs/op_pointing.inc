.. _pointing:

Pointing Matrices
----------------------------

A "pointing matrix" in TOAST terms is the sparse matrix that describes how sky signal is projected to the timestream.  In particular, the model we use is

.. math::

    d_t = \mathcal{A}_{tp} s_p + n_t

where we write :math:`s_p` as a column vector having a number of rows given by the number of pixels in the sky.  So the :math:`\mathcal{A}_{tp}` matrix has a number of rows given by the number of time samples and a column for every sky pixel.  In practice, the pointing matrix is sparse, and we only store the nonzero elements in each row.  Also, our sky model often includes multiple terms (e.g. I, Q, and U).  This is equivalent to having a set of values at each sky pixel.  In TOAST we represent the pointing matrix as a vector of pixel indices (one for each sample) and a 2D array of "weights" whose values are the nonzero values of the matrix for each sample.  TOAST includes a generic HEALPix operator to generate a pointing matrix.


Generic HEALPix Representation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. autoclass:: toast.todmap.OpPointingHpix
    :members:

Each experiment might create other specialized pointing matrices used in solving for instrument-specific signals.
