#ifndef SPARSE_GRAPH_MISSION_GRAPH_H_
#define SPARSE_GRAPH_MISSION_GRAPH_H_

#include <unordered_map>
#include <vector>

#include <vi-map/vi-map.h>

#include "sparse-graph/common/representative-node.h"
#include "sparse-graph/partitioners/base-partitioner.h"

namespace spg {

class MissionGraph {
 public:
  MissionGraph();
  void addNewVertices(
      const uint32_t submap_id, const pose_graph::VertexIdList& vertices);

  RepresentativeNodeVector computeSparseGraph(
      BasePartitioner* partitioner) const;

  const pose_graph::VertexIdList& getVerticesForId(
      const uint32_t submap_id) const noexcept;

  bool containsSubmap(const uint32_t submap_id) const noexcept;

  size_t size() const noexcept;

 private:
  std::unordered_map<uint32_t, pose_graph::VertexIdList> all_vertex_partitions_;
};

}  // namespace spg

#endif  //  SPARSE_GRAPH_MISSION_GRAPH_H_
