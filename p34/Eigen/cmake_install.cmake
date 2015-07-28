# Install script for directory: /home/skardash/Downloads/eigen/Eigen

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/eigen3/Eigen/SparseQR;/usr/local/include/eigen3/Eigen/SparseLU;/usr/local/include/eigen3/Eigen/Geometry;/usr/local/include/eigen3/Eigen/Sparse;/usr/local/include/eigen3/Eigen/PardisoSupport;/usr/local/include/eigen3/Eigen/SVD;/usr/local/include/eigen3/Eigen/StdVector;/usr/local/include/eigen3/Eigen/MetisSupport;/usr/local/include/eigen3/Eigen/StdDeque;/usr/local/include/eigen3/Eigen/Core;/usr/local/include/eigen3/Eigen/PaStiXSupport;/usr/local/include/eigen3/Eigen/QtAlignedMalloc;/usr/local/include/eigen3/Eigen/Jacobi;/usr/local/include/eigen3/Eigen/Cholesky;/usr/local/include/eigen3/Eigen/Dense;/usr/local/include/eigen3/Eigen/Eigenvalues;/usr/local/include/eigen3/Eigen/LU;/usr/local/include/eigen3/Eigen/Eigen2Support;/usr/local/include/eigen3/Eigen/SuperLUSupport;/usr/local/include/eigen3/Eigen/CholmodSupport;/usr/local/include/eigen3/Eigen/Array;/usr/local/include/eigen3/Eigen/LeastSquares;/usr/local/include/eigen3/Eigen/SparseCholesky;/usr/local/include/eigen3/Eigen/Householder;/usr/local/include/eigen3/Eigen/StdList;/usr/local/include/eigen3/Eigen/IterativeLinearSolvers;/usr/local/include/eigen3/Eigen/QR;/usr/local/include/eigen3/Eigen/SPQRSupport;/usr/local/include/eigen3/Eigen/SparseCore;/usr/local/include/eigen3/Eigen/Eigen;/usr/local/include/eigen3/Eigen/UmfPackSupport;/usr/local/include/eigen3/Eigen/OrderingMethods")
FILE(INSTALL DESTINATION "/usr/local/include/eigen3/Eigen" TYPE FILE FILES
    "/home/skardash/Downloads/eigen/Eigen/SparseQR"
    "/home/skardash/Downloads/eigen/Eigen/SparseLU"
    "/home/skardash/Downloads/eigen/Eigen/Geometry"
    "/home/skardash/Downloads/eigen/Eigen/Sparse"
    "/home/skardash/Downloads/eigen/Eigen/PardisoSupport"
    "/home/skardash/Downloads/eigen/Eigen/SVD"
    "/home/skardash/Downloads/eigen/Eigen/StdVector"
    "/home/skardash/Downloads/eigen/Eigen/MetisSupport"
    "/home/skardash/Downloads/eigen/Eigen/StdDeque"
    "/home/skardash/Downloads/eigen/Eigen/Core"
    "/home/skardash/Downloads/eigen/Eigen/PaStiXSupport"
    "/home/skardash/Downloads/eigen/Eigen/QtAlignedMalloc"
    "/home/skardash/Downloads/eigen/Eigen/Jacobi"
    "/home/skardash/Downloads/eigen/Eigen/Cholesky"
    "/home/skardash/Downloads/eigen/Eigen/Dense"
    "/home/skardash/Downloads/eigen/Eigen/Eigenvalues"
    "/home/skardash/Downloads/eigen/Eigen/LU"
    "/home/skardash/Downloads/eigen/Eigen/Eigen2Support"
    "/home/skardash/Downloads/eigen/Eigen/SuperLUSupport"
    "/home/skardash/Downloads/eigen/Eigen/CholmodSupport"
    "/home/skardash/Downloads/eigen/Eigen/Array"
    "/home/skardash/Downloads/eigen/Eigen/LeastSquares"
    "/home/skardash/Downloads/eigen/Eigen/SparseCholesky"
    "/home/skardash/Downloads/eigen/Eigen/Householder"
    "/home/skardash/Downloads/eigen/Eigen/StdList"
    "/home/skardash/Downloads/eigen/Eigen/IterativeLinearSolvers"
    "/home/skardash/Downloads/eigen/Eigen/QR"
    "/home/skardash/Downloads/eigen/Eigen/SPQRSupport"
    "/home/skardash/Downloads/eigen/Eigen/SparseCore"
    "/home/skardash/Downloads/eigen/Eigen/Eigen"
    "/home/skardash/Downloads/eigen/Eigen/UmfPackSupport"
    "/home/skardash/Downloads/eigen/Eigen/OrderingMethods"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/skardash/Downloads/eigen_build/Eigen/src/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

