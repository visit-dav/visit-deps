
#ifndef BL_FARRAYBOX_H
#define BL_FARRAYBOX_H

#include <Pointers.H>
#include <Box.H>
#include <BaseFab.H>
#include <REAL.H>
#include <SPACE.H>

class FArrayBox;

//
// A Class Facilitating I/O for Fabs
//
// This data-less class aids I/O for FABs and encapsulates information
// about the floating point format being used in output.
// Note that the "new" format for writing out FABs is self-describing;
//    i.e. we can always read in a FAB written in the "new" format.  For this
// reason, it is usually preferable to write FABs out in the native
//    format on the machine, unless you're doing computations in 64 bit and
// only want to write out 32 bit FABs.
//
// With the exception of the enumeration constants, this class is
// primarily for FArrayBox implementors; i.e. user's shouldn't
// call any of the member functions in this class directly.
//

class FABio
{
public:
    //
    // An enum which controls precision of FAB output.
    // Valid values are FAB_FLOAT and FAB_DOUBLE.  This
    // is deprecated; i.e. please don't use it except
    // for reading old FABs as it will probably be going
    // away in a later release.
    //
    enum Precision
    {
        FAB_FLOAT = 0,
        FAB_DOUBLE
    };
    //
    // An enum which controls format of FAB output.
    //
    // Valid values are FAB_ASCII, FAB_IEEE, FAB_NATIVE,
    // FAB_8BIT and FAB_IEEE_32;
    //
    // FAB_ASCII: write the FAB out in ASCII format.
    //
    // FAB_8BIT: write the FAB out with all floating-point
    // values scaled to range 0 - 255.
    //
    // FAB_NATIVE: write out floating-point values in the native
    // format.  This is usually the "best" choice of formats.
    //
    // FAB_IEEE_32: write out floating-point values in IEEE 32
    // bit normal format.  This is recommended for use when your
    // internal computations are done in 64 bits and you want to save
    // space when writing out the FABs.
    //
    // FAB_IEEE: this is deprecated.  It is identical to
    // FAB_IEEE_32.
    //
    enum Format
    {
        FAB_ASCII = 0,
        FAB_IEEE,
        FAB_NATIVE,
        //
        // This is set to four so that when reading in an old FAB,
        // we don't get confused when we see an old FAB_8BITRLE file.
        //
        FAB_8BIT = 4,
        FAB_IEEE_32,
        FAB_NATIVE_32
    };
    //
    // An enum which controls byte ordering of FAB output.
    // Valid values are FAB_NORMAL_ORDER, FAB_REVERSE_ORDER,
    // and FAB_REVERSE_ORDER_2.  This is deprecated; i.e. please
    // don't use it except for reading old FABs as it will probably
    // be going away in a later release.  These exist solely to
    // describe the ordering of "old" FABs that you want to read.
    //
    enum Ordering
    {
        FAB_NORMAL_ORDER,
        FAB_REVERSE_ORDER,
        FAB_REVERSE_ORDER_2
    };
    //
    //The virtual destructor.
    //
    virtual ~FABio ();
    //
    // Pure virtual function.  Derived classes MUST override this
    // function to read an FArrayBox from the istream, under the
    // assumption that the header has alread been read.
    //
    virtual void read (std::istream& is,
                       FArrayBox&    fb) const = 0;
    //
    // Pure virtual function.  Derived classes MUST override this
    // function to write the FArrayBox to the ostream, under the
    // assumption that the header for the FAB has already been
    // written.  Write it out as if it only had num_comp components
    // with component comp being the first one.
    //
    virtual void write (std::ostream&    os,
                        const FArrayBox& fb,
                        int              comp,
                        int              num_comp) const = 0;
    //
    // Pure virtual function.  Derived classes MUST override this
    // function to skip over the next FAB f in the istream, under the
    // assumption that the header for the FAB f has already been
    // skpped over.
    //
    virtual void skip (std::istream& is,
                       FArrayBox&    f) const = 0;

    virtual void skip (std::istream& is,
                       FArrayBox&    f,
		       int           nCompToSkip) const = 0;
    //
    // Write out a header describing FArrayBox f that contains
    // nvar components.  It must be the case that nvar <= f.nComp().
    //
    virtual void write_header (std::ostream&    os,
                               const FArrayBox& f,
                               int              nvar) const;
    //
    // Read in the header from the istream.
    // Returns a new'd FABio of the written-out type.
    // Complements write_header.  The user is responsible
    // for delete'ing the returned FABio*.  The FArrayBox f is
    // resized to be on the Box and number of components read
    // in from the header file.  This is in preparation for
    // next doing a read.  This is split up so that we can make
    // the read functions virtual, while having all the code for
    // detailing the type of FArrayBox that was written out in one place.
    //
    static FABio* read_header (std::istream& is,
                               FArrayBox&    f);

    // Same as above except create a single component fab with
    // data from the compIndex component of the istream fab.
    // Return the number of available components in the istream fab.
    static FABio* read_header (std::istream& is,
                               FArrayBox&    f,
			       int           compIndex,
			       int&          nCompAvailable);
};

/*
  A Fortran Array of REALs

  Fortran Array Box's (generally called FAB's) are objects constructed
  to emulate the FORTRAN array.  Useful operations can be performed
  upon FAB's in C++, and they provide a convenient interface to
  FORTRAN when it is necessary to retreat into that language.

  FArrayBox is derived from BaseFab<Real>.
  FArrayBox adds additional useful capabilities which make sense
  for Real types, such as I/O and L**p norms.

  FArrayBox's may be output in various format's with various
  precisions. Available formats are ascii, IEEE 32, native, and
  8bit.  Ascii is self explanatory.  IEEE 32 is the standard on
  most microprocessor based computers; it specifies that output should be in
  IEEE 32 bit floating point format in normal order.  Native is the most
  efficient, but not necessarily most portable, I/O format for a
  given computer.  8bit is a 8 bit format, suitable for graphics output.
  In general, you probably want to use NATIVE, unless you need to write
  your data out with less precision than your computation in order to
  save space.

  The format and precision may be set in a file read by the ParmParse
  class by the "fab.format" variable.  Allowed values are NATIVE, ASCII,
  8BIT and IEEE32.

  FABs written using operator<< are always written in ASCII.
  FABS written using writOn use the FABio::Format specified with
  setFormat or the FABio::Format specified in the ParmParse file
  read by init. If the FABio::Format is not set explicitly by either
  of these two methods, then it defaults to NATIVE.

  The C pre-processor macro BL_SPACEDIM must be defined to use
  this class.  The internal precision of FARRAYBOX objects is
  set by defining either BL_USE_FLOAT or BL_USE_DOUBLE

  This is NOT a polymorphic class.

  This class does NOT provide a copy constructor or assignment operator.
*/

class FArrayBox
    :
    public BaseFab<Real>
{
    //
    // FABio is a friend of ours.
    //
    friend class FABio;
public:
    //
    // Construct an invalid FAB with no memory.
    //
    FArrayBox ();
    //
    // Construct an initial FAB with the data space allocated but
    // not inititialized. ncomp is the number of components
    // (variables) at each data point in the Box.
    //
    explicit FArrayBox (const Box& b,
                        int        ncomp=1);
    //
    // Set the fab to the value r.
    //
    FArrayBox& operator= (const Real& r);
    //
    //  The destructor.
    //
    ~FArrayBox ();
    //
    // Are there any NaNs in the FAB?
    // This may return false, even if the FAB contains NaNs, if the machine
    // doesn't support the appropriate NaN testing functions.
    //
    bool contains_nan () const;

    bool contains_nan (const Box& bx, int scomp, int ncomp) const;
    //
    // These versions return the cell index (though not the component) of
    // the first location of a NaN if there is one.
    //
    bool contains_nan (IntVect& where) const;

    bool contains_nan (const Box& bx, int scomp, int ncomp, IntVect& where) const;
    //
    // Are there any Infs in the FAB?
    // This may return false, even if the FAB contains Infs, if the machine
    // doesn't support the appropriate Inf testing functions.
    //
    bool contains_inf () const;

    bool contains_inf (const Box& bx, int scomp, int ncomp) const;
    //
    // These versions return the cell index (though not the component) of
    // the first location of an Inf if there is one.
    //
    bool contains_inf (IntVect& where) const;

    bool contains_inf (const Box& bx, int scomp, int ncomp, IntVect& where) const;
    //
    // For debugging purposes we hide BaseFab version and do some extra work.
    //
    void resize (const Box& b,
                 int        N = 1);
    //
    // Compute the Lp-norm of this FAB using components
    // (scomp : scomp+ncomp-1).  p < 0  -> ERROR.
    // p = 0  -> infinity norm (max norm).
    // p = 1  -> sum of ABS(FAB)
    // p > 1  -> Lp-norm
    //
    Real norm (int p     = 2,
               int scomp = 0,
               int ncomp = 1) const;
    //
    // Same as above except only on given subbox.
    //
    Real norm (const Box& subbox,
               int        p     = 2,
               int        scomp = 0,
               int        ncomp = 1) const;
    //
    // Write FABs in ASCII form.
    //
    friend std::ostream& operator<< (std::ostream&    os,
                                     const FArrayBox& fb);
    //
    // Read FABs in ASCII form.
    //
    friend std::istream& operator>> (std::istream& is,
                                     FArrayBox&    fb);
    //
    // Writes out the FAB in whatever format you've set.
    // The default format is ASCII.
    //
    void writeOn (std::ostream& of) const;
    //
    // Write only selected range of components.  comp specifies
    // from which component (starting at 0) to write at each
    // point in space.  num_comp specifies how many data points
    // to write out at each point is space -- it defaults to 1.
    // It must be the case the comp >= 0 && num_comp >= 1 &&
    // (comp+num_comp) <= nComp().  The FAB is written out in
    // whatever format you've set, with the default format being
    // ASCII.  The FAB that is written to disk will be an
    // num_comp component FAB.
    //
    void writeOn (std::ostream& of,
                  int           comp,
                  int           num_comp=1) const;
    //
    // Read FAB from istream.  Format is as it was written out.
    //
    void readFrom (std::istream& is);
    //
    // Read FAB from istream.  Format is as it was written out.
    // This creates a single component FAB with data from
    // compIndex of the FAB from the istream.
    // Returns the number of components available in the fab.
    //
    int readFrom (std::istream& is, int compIndex);
    //
    // Skip over the next FAB from the input stream.
    // Return the Box defining the domain of the FAB and the
    // number of components.
    //
    static Box skipFAB (std::istream& is,
                        int&          num_comp);
    //
    // Skip over the next FAB from the input stream.
    //
    static void skipFAB (std::istream& is);
    //
    // Set the FABio::Format in the program.
    // This is the preferred way to set the output format
    // in "new" FABs.  When desiging new programs, this should
    // be the only function that needs to be called in order
    // to set the format.
    //
    static void setFormat (FABio::Format fmt);
    //
    // Gets the FABio::Format set in the program.
    //
    static FABio::Format getFormat ();
    //
    // Set the FABio::Ordering for reading old FABs.  It does
    // NOT set the ordering for output.
    // This is deprecated.  It exists only to facilitate
    // reading old FABs.  When you're reading in an "old" FAB,
    // you must set the Ordering, before attempting
    // to read it in.  This is because FABs written out in the
    // "old" format weren't self-describing; i.e. information
    // such as the Ordering was lost when the "old" FAB was
    // written out.
    //
    static void setOrdering (FABio::Ordering ordering);
    //
    // Gets the FABio::Ordering set in the program.  This is
    // deprecated.  It does NOT do the right thing with the
    // new FAB I/O format.
    //
    static FABio::Ordering getOrdering ();
    //
    // Set the FABio::Precision.  This is deprecated.  It
    // is not useful with the "new" FAB I/O format.
    //
    static void setPrecision (FABio::Precision precision);
    //
    // Returns the FABio::Precision.  This is deprecated.  It
    // is not useful with the "new" FAB I/O format.  Always
    // returns FABio::Float.
    //
    static FABio::Precision getPrecision ();
    //
    // Returns reference to the FABio object used by the program.
    //
    static const FABio& getFABio ();
    //
    // Sets the FABio object used by the program.  It is an error
    // if the passed pointer rd is the null pointer.
    //
    static void setFABio (FABio* rd);

    static bool set_do_initval (bool tf);
    static bool get_do_initval ();
    static Real set_initval    (Real iv);
    static Real get_initval    ();
    //
    // Initialize from ParmParse with "fab" prefix.
    //
    static void Initialize ();
    static void Finalize ();

private:
    //
    // Format and ordering for all FAB output.
    // This stuff exists solely to support reading old FABs.
    //
    static FABio::Format   format;
    static FABio::Ordering ordering;
    //
    // The FABio pointer describing our output format.
    //
    static FABio* fabio;
    //
    // initial value
    //
    static bool do_initval;
    static Real initval;
    static bool init_snan;
    //
    // These are not allowed.
    //
    FArrayBox (const FArrayBox&);
    FArrayBox& operator= (const FArrayBox&);
};

#endif /*BL_FARRAYBOX_H*/
