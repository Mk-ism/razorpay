package com.infosys.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;



@Repository
public interface SimDetailsRepo extends JpaRepository<com.infosys.model.SimDetails, Integer> {

	
	   List<SimDetailsRepo> findById(int id);
	   
	 //  List<SimDetails> findByserviceNumberAndsimNumber(Long id1,Long id2);
	   
	   
	   
	
}
