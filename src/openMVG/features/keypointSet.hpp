
// Copyright (c) 2012, 2013 Pierre MOULON.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENMVG_FEATURES_KEYPOINTSET_HPP
#define OPENMVG_FEATURES_KEYPOINTSET_HPP

#include "openMVG/features/feature.hpp"
#include "openMVG/features/descriptor.hpp"
#include <string>

namespace openMVG {

/// Association storage of associated feature and descriptor for a given image.
/// Load, save, R/W accessor operation.
///
/// typedef vector<SIOPointFeature> featsT;
/// typedef vector<Descriptor<uchar,128> > descsT;
/// KeypointSet< featsT, descsT > kpSet;
template<typename FeatureT, typename DescriptorT>
class KeypointSet {
public:

  /// Read from files the feats and their corresponding descriptors.
  bool loadFromFile(
    const std::string& sfileNameFeats,
    const std::string& sfileNameDescs)
  {
    return loadFeatsFromFile(sfileNameFeats, _feats)
          & loadDescsFromFile(sfileNameDescs, _descs);
  }

  /// Export in two separate files the feats and their corresponding descriptors.
  bool saveToFile(
    const std::string& sfileNameFeats,
    const std::string& sfileNameDescs) const
  {
    return saveFeatsToFile(sfileNameFeats, _feats)
          & saveDescsToFile(sfileNameDescs, _descs);
  }

  /// Read from files the feats and their corresponding descriptors
  ///  descriptor in binary to save place
  bool loadFromBinFile(
    const std::string& sfileNameFeats,
    const std::string& sfileNameDescs)
  {
    return loadFeatsFromFile(sfileNameFeats, _feats)
          & loadDescsFromBinFile(sfileNameDescs, _descs);
  }

  /// Export in two separate files the feats and their corresponding descriptors
  ///  descriptor in binary to save place
  bool saveToBinFile(
    const std::string& sfileNameFeats,
    const std::string& sfileNameDescs) const
  {
    return saveFeatsToFile(sfileNameFeats, _feats)
          & saveDescsToBinFile(sfileNameDescs, _descs);
  }

  /// Mutable and non-mutable FeatureT getters.
  FeatureT & features() { return _feats; }
  const FeatureT & features() const { return _feats; }

  /// Mutable and non-mutable DescriptorT getters.
  DescriptorT & descriptors() { return _descs; }
  const DescriptorT & descriptors() const { return _descs; }

private:
  FeatureT _feats;
  DescriptorT _descs;
};

} // namespace openMVG

#endif // OPENMVG_FEATURES_KEYPOINTSET_HPP
